#[allow(dead_code)]
fn scan<T: std::str::FromStr>() -> T
{
	static mut BUFFER: Vec<String> = vec![];
	loop {
		if let Some(token) = unsafe { BUFFER.pop() } {
			return token.parse().ok().unwrap();
		}
		let mut input = String::new();
		std::io::stdin().read_line(&mut input).ok();
		unsafe { BUFFER = input.split_whitespace().rev().map(String::from).collect(); }
	}
}

const MOD: i64 = (7 * 17 * (1 << 23)) + 1;

fn ntt(a: &mut Vec<i64>, dir: bool)
{
	let w = {
		let mut v: Vec<i64> = vec![if dir { 31 } else { 128805723 }];
		while v.last().unwrap() != &1 {
			v.push(v.last().unwrap().pow(2) % MOD);
		}
		v.reverse();
		v
	};

	fn lg(x: usize) -> usize { (usize::BITS - 1 - x.leading_zeros()) as usize }

	assert!(a.len().is_power_of_two());
	let n = a.len();
	let lgn = lg(n);

	let rev = {
		let mut v = vec![0];
		for x in 1..n {
			v.push(v[x/2]/2 ^ x%2 << lgn-1);
		}
		v
	};

	for i in 0..n {
		if i > rev[i] {
			a.swap(i, rev[i]);
		}
	}

	for len in (1..=lgn).map(|x| 1<<x) {
		for l in (0..n).step_by(len) {
			let m = l + len/2;
			let mut wi = 1;
			for i in 0..len/2 {
				let mut x = (a[l + i] + wi*a[m + i]) % MOD;
				let mut y = (a[l + i] + (MOD - wi)*a[m + i]) % MOD;
				if dir {
					x = if x&1 == 1 {x + MOD} else {x} / 2;
					y = if y&1 == 1 {y + MOD} else {y} / 2;
				}
				a[l + i] = x;
				a[m + i] = y;
				wi = wi * w[lg(len)] % MOD;
			}
		}
	}
}

fn pow2(a: &Vec<i64>) -> Vec<i64>
{
	let mut ans = a.clone();
	ans.resize(ans.len().next_power_of_two() * 2, 0);
	ntt(&mut ans, false);
	ans = ans.into_iter().map(|x| x*x % MOD).collect();
	ntt(&mut ans, true);
	ans.resize(a.len(), 0);
	ans
}

fn main()
{
	let (n, k, f): (usize, usize, usize) = (scan(), scan(), scan());

	let mut a = vec![vec![0i64; 2*k+1]; n+1];
	let mut a2 = vec![vec![0i64; 2*k+2]; n+1];
	let mut b = a.clone();
	let mut b2 = a2.clone();

	for i in 0..a2[0].len() { a2[0][i] = 1; }
	for i in 0..=k { b[0][i] = 1; b2[0][i] = (k+1 - i) as i64; }
	
	for i in 1..=n {
		a[i] = pow2(&b[i-1]);
		for j in (0..=2*k).rev() { a2[i][j] = (a[i][j] + a2[i][j+1]) % MOD; }
		for j in 0..=k { b[i][j] = ((k-j) as i64 * a[i][j] + a2[i][j]) % MOD; }
		for j in (0..=k).rev() { b2[i][j] = (b[i][j] + b2[i][j+1]) % MOD; }
	}

	println!("{}", if f < a[n].len() { a[n][f] } else { 0 });
}