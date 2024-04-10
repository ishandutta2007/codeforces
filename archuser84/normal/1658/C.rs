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

fn solve(v: &[i32]) -> bool
{
    if v.iter().filter(|&x| *x == 1).count() != 1 { return false; }
    let n = v.len();
    for i in 1..n {
        if v[i] > v[i-1] + 1 {
            return false;
        }
    }
    if v[0] > v[n-1] + 1 {
        return false;
    }
    return true;
}

fn main()
{
    let scan = &mut Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t: i32 = scan.next();
    for _ in 0..t {
        let n: usize = scan.next();
        let v: Vec<i32> = (0..n).map(|_| scan.next()).collect();
        writeln!(out, "{}", if solve(&v) { "YES" } else { "NO" }).expect("fail");
    }
}