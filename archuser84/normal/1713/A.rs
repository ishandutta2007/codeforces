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

fn main()
{
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let t: i32 = scan.next();
    for _ in 0..t {
        let (mut mxx, mut mnx, mut mxy, mut mny) = (0, 0, 0, 0);
        let n: i32 = scan.next();
        for _ in 0..n {
            let (x, y): (i32, i32) = (scan.next(), scan.next());
            mnx = mnx.min(x);
            mxx = mxx.max(x);
            mny = mny.min(y);
            mxy = mxy.max(y);
        }
        writeln!(out, "{}", 2*(mxx + mxy - mnx - mny)).ok();
    }
}