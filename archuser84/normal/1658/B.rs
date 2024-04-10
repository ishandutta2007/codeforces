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

fn main()
{
    let scan = &mut Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t: i32 = scan.next();
    for _ in 0..t {
        let n: u64 = scan.next();
        if n%2 == 1 {
            writeln!(out, "0");
        } else {
            let mut ans = 1u64;
            let MOD = 998244353u64;
            for i in 1..=n/2 {
                ans = ans*i % MOD;
            }
            ans = ans*ans % MOD;
            writeln!(out, "{}", ans);
        }
    }
}