#[allow(unused_imports)]
use std::io::{BufWriter, stdin, stdout, Write};
 
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

fn main() {
    let scan = &mut Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t: i32 = scan.next();
    for _ in 0..t {
        let _n: i32 = scan.next();
        let s: String = scan.next();
        let mut lst = -100i32;
        let mut ans = 0i32;
        for (i, &x) in s.as_bytes().iter().enumerate() {
            if x == b'0' && (i as i32) - lst - 1 < 2 {
                ans += 2-((i as i32)-lst-1);
            }
            if x == b'0' {
                lst = i as i32;
            }
        }
        writeln!(out, "{}", ans).expect("fail");
    }
}