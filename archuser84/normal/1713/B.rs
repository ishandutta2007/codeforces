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

fn is_hill(a: &[i32]) -> bool
{
    let mut ind = 0usize;
    for (i, &x) in a.iter().enumerate() {
        if x > a[ind] {
            ind = i;
        }
    }
    for i in (0usize..ind).rev() {
        if a[i] > a[i+1] {
            return false;
        }
    }
    for i in ind+1..a.len() {
        if a[i] > a[i-1] {
            return false;
        }
    }
    true
}

fn main()
{
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let t: i32 = scan.next();
    for _ in 0..t {
        let n: usize = scan.next();
        let a: Vec<i32> = (0usize..n).map(|_| scan.next()).collect();
        writeln!(out, "{}", if is_hill(&a) { "YES" } else { "NO" }).ok();
    }
}