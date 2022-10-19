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

fn divs(x: u64) -> Vec<u64>
{
    let mut ans = vec![];
    for y in 1.. {
        if y * y > x {
            break;
        }
        if x % y == 0 {
            ans.push(y);
            if y * y != x {
                ans.push(x/y);
            }
        }
    }
    ans
}

fn main()
{
    use std::io::*;
    let mut out = BufWriter::new(stdout());
    'dard: for _ in 0..scan::<usize>() {
        let (a, b, c, d): (u64, u64, u64, u64) = (scan(), scan(), scan(), scan());
        let (A, B) = (divs(a), divs(b));
        let ab = a * b;
        for &x in &A { for &y in &B {
            let xy = x * y;
            let ixy = ab / xy;
            if a/xy != c/xy && b/ixy != d/ixy {
                writeln!(out, "{} {}", (c/xy)*xy, (d/ixy)*ixy).unwrap();
                continue 'dard;
            }
        }}
        writeln!(out, "-1 -1").unwrap();
    }
}