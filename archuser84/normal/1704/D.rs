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

fn solve(scan: &mut Scanner, out: &mut BufWriter<Stdout>)
{
    let (mut mn, mut mx) = (i64::MAX, i64::MIN);
    let mut ans = 0;
    let (n, m): (i32, i32) = (scan.next(), scan.next());
    for i in 0..n {
        let mut sum = 0i64;
        for j in 0..m {
            sum += scan.next::<i64>() * (j as i64);
        }
        if sum > mx {
            ans = i;
            mx = sum;
        }
        if sum < mn {
            mn = sum;
        }
    }
    writeln!(out, "{} {}", ans+1, mx-mn).ok();
}

fn main()
{
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let t: i32 = scan.next();
    for _ in 0..t {
        solve(&mut scan, &mut out);
    }
}