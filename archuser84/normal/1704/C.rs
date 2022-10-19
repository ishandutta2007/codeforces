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

fn main()
{
	use std::io::*;
	let mut buf = BufWriter::new(stdout());
	for _ in 0..scan::<i32>() {
		let (n, m) = (scan::<usize>(), scan::<usize>());
		let mut v: Vec<i64> = (0..m).map(|_| scan::<i64>()).collect();
		v.sort();
		let mut u: Vec<i64> = (0..m-1).map(|i| v[i+1]-v[i] - 1).collect();
		u.push(n as i64 + v[0] - v[m-1] - 1);
		u.sort();
		u.reverse();
		let mut ans = 0i64;
		for (i, &x) in u.iter().enumerate() {
			let i = i as i64;
			if x - 4*i == 1 {
				ans += 1;
				break;
			}
			if x <= 4*i + 1 {
				break;
			}
			ans += x - 4*i - 1
		}
		writeln!(buf, "{}", n as i64 - ans).unwrap();
	}
}