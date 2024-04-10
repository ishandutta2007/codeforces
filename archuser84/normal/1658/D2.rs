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

fn dc(v: Vec<usize>, u: Vec<usize>, i: usize) -> usize
{
    if v.len() == 0 {
        return 0;
    }
    let mut ans = 0;
    let (v0, v1) =
        if v.iter().filter(|&x| (*x&(1<<i)) > 0).count()
           != u.iter().filter(|&x| (*x&(1<<i)) > 0).count() {
            ans ^= 1 << i;
            v.iter().partition(|&x| (*x&(1<<i)) > 0)
        } else {
            v.iter().partition(|&x| (*x&(1<<i)) == 0)
        };
    let (u0, u1) = u.iter().partition(|&x| (*x&(1<<i)) == 0);
    if i > 0 {
        let mut x = 0;
        x |= dc(v0, u0, i-1);
        x |= dc(v1, u1, i-1);
        ans ^= x;
    }
    ans
}

fn main()
{
    let scan = &mut Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t: i32 = scan.next();
    for _ in 0..t {
        let l: usize = scan.next();
        let r: usize = scan.next::<usize>() + 1;
        let v: Vec<usize> = (l..r).map(|_| scan.next()).collect();
        let u: Vec<usize> = (l..r).collect();
        
        let bits: usize = 17;
        let ans = dc(v, u, bits-1);

        writeln!(out, "{}", ans).expect("fail");
    }
}