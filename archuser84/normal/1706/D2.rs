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

#[derive(Debug)]
struct Foo {
	x: u64,
	y: u64,
	stage: i32,
}

impl Foo {
	fn new(x: u64, k: u64) -> Self { 
		if k * k <= x {
			Self {x, y: k, stage: 1 }
		} else {
			Self {x, y: x/k, stage: 0}
		}
	}
}

impl Iterator for Foo {
	type Item = u64;
	fn next(&mut self) -> Option<Self::Item>
	{
		if self.stage == 1 && self.y == 0 {
			None
		} else if self.stage == 0 {
			let ans = self.y;
			self.y += 1;
			if self.y.pow(2) >= self.x {
				self.stage = 1;
				while (self.x/self.y).pow(2) < self.x {
					self.y -= 1;
				}
			}
			Some(ans)
		} else {
			let ans = self.x/self.y;
			self.y -= 1;
			Some(ans)
		}
	}
}

fn solve() -> u64
{
	let (n, k) = (scan::<usize>(), scan::<u64>());
	let mut q: Vec<Vec<usize>> = vec![vec![]; 100_010];
	let mut it: Vec<Foo> = vec![];
	let mut mx = 0u64;
	for i in 0..n {
		let x = scan::<u64>();
		it.push(Foo::new(x, k));
		let x = it[i].next().unwrap();
		q[x as usize].push(i);
		mx = mx.max(x);
	}
	let mut ans = mx;
	for i in 0..q.len() {
		for j in std::mem::take(&mut q[i]) {
			if let Some(x) = it[j].next() {
				assert!(x as usize > i);
				mx = mx.max(x);
				q[x as usize].push(j);
			} else {
				return ans;
			}
		}
		ans = ans.min(mx - i as u64 - 1);
	}
	unreachable!();
}



fn main()
{
	use std::io::*;
	let mut buf = BufWriter::new(stdout());
	for _ in 0..scan::<i32>() {
		writeln!(buf, "{}", solve()).unwrap();
	}
}