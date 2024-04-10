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

fn main()
{
    use std::io::*;
    let mut out = BufWriter::new(stdout());
    for _ in 0..scan::<usize>() {
        let (n, c) = (scan::<usize>(), scan::<char>() as u8);
        let s = Vec::<u8>::from(scan::<String>());
        let mut lst = s.iter().position(|&x| x == b'g').unwrap();
        let mut ans = 0;
        for (i, &x) in s.iter().enumerate().rev() {
            if x == b'g' {
                lst = i;
            }
            if x == c {
                ans = ans.max((n + lst - i) % n);
            }
        }
        writeln!(out, "{}", ans).unwrap();
    }
}