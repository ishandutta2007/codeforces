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


fn get_bit(x: u32, pos: u32) -> usize { (x >> pos & 1) as usize }

#[derive(Default)]
struct Node {
	child: [Option<Box<Node>>; 2],
	max: [i32; 2],
}

impl Node {
	fn get(&self, x: u32, ind: u32) -> i32
	{
		let mut cur = self;
		let mut ans = 0;
		for pos in (0..u32::BITS).rev() { // pos is next
			let bit = get_bit(x ^ ind, pos);
			if let Some(node) = &cur.child[1-bit] {
				ans = ans.max(node.max[1 - get_bit(x, pos)]);
			}
			if let Some(node) = &cur.child[bit] {
				cur = node;
			} else {
				break;
			}
		}
		ans + 1
	}

	fn insert(&mut self, x: u32, ind: u32, val: i32)
	{
		let mut cur = self;
		for pos in (0..u32::BITS).rev() { // pos will be added
			let bit = get_bit(x ^ ind, pos);
			let ind_bit = get_bit(ind, pos);
			if let None = &cur.child[bit] {
				cur.child[bit] = Some(Box::new(Self::default()));
			}
			cur = cur.child[bit].as_mut().unwrap();
			cur.max[ind_bit] = cur.max[ind_bit].max(val);
		}
	}
}

fn solve() -> i32
{
	let mut root = Node::default();
	let n = scan::<usize>();
	let mut ans = 0;
	for (i, x) in (0..n).map(|_| scan::<u32>()).enumerate() {
		let val = root.get(x, i as u32);
		ans = ans.max(val);
		root.insert(x, i as u32, val);
	}
	ans
}

fn main()
{
	use std::io::*;
	let mut buf = BufWriter::new(stdout());
	for _ in 0..scan() {
		writeln!(buf, "{}", solve()).ok();
	}
}