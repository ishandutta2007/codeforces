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

struct Comb {
	modu: i64,
	fact: Vec<i64>,
	ifact: Vec<i64>,
}

impl Comb {
	fn mpow(&self, mut x: i64, mut y: i64) -> i64
	{
		let mut ans = 1;
		while y > 0 {
			if y&1 == 1 {
				ans = ans*x % self.modu;
			}
			x = x*x % self.modu;
			y >>= 1;
		}
		ans
	}

	fn inv(&self, x: i64) -> i64 { self.mpow(x, self.modu-2) }

	fn new(modu: i64, size: usize) -> Self
	{
		assert!(size > 1);
		let mut tmp = Self { modu, fact: vec![0; size], ifact: vec![0; size] };
		tmp.fact[0] = 1;
		for i in 1..size {
			tmp.fact[i] = tmp.fact[i-1] * i as i64 % modu;
		}
		tmp.ifact[size-1] = tmp.inv(tmp.fact[size-1]);
		for i in (1..size).rev() {
			tmp.ifact[i-1] = tmp.ifact[i] * i as i64 % modu;
		}
		tmp
	}

	fn C(&self, n: i64, r: i64) -> i64
	{
		if 0 <= r && r <= n {
			self.fact[n as usize] * self.ifact[r as usize] % self.modu * self.ifact[(n-r) as usize] % self.modu
		} else {
			0
		}
	}

}

fn main()
{
	let n = scan::<i64>();
	let modu = scan::<i64>();
	let cb = Comb::new(modu, n as usize + 10);

	let mut ans = 0i64;
	for a in 0..=n {
		let b = n-a;
        let kooft_step = cb.inv(b) * (n-1) % modu;
        let mut kooft = cb.mpow(b, a);
		let mut s = 0i64;
		for c in 0..=std::cmp::min(a, b) {
			s += cb.C(b-1, c-1) * cb.C(a, c) % modu * kooft % modu;
            kooft = kooft * kooft_step % modu;
		}
		s %= modu;
		ans += s * cb.C(n, a) % modu * cb.fact[b as usize] % modu;
	}
	ans %= modu;
	println!("{}", ans);
}