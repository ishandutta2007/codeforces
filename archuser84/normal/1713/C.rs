#[allow(unused_imports)]
use std::io::*;
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn solve(n: i32) -> Vec<i32>
{
    if n == 0 {
        return vec![];
    }
    let x: i32 = ((n-1) as f64).sqrt().ceil() as i32;
    let y = x*x - (n-1);
    let mut ans = solve(y);
    for i in (y..=x*x-y).rev() {
        ans.push(i);
    }
    ans
}


fn main()
{
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let t: i32 = scan.next();
    for _ in 0..t {
        let n: i32 = scan.next();
        for i in solve(n) {
            write!(out, "{} ", i).ok();
        }
        writeln!(out, "").ok();
    }
}