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
        let n: usize = scan();
        let mut idx = vec![0usize; n];
        for (i, x) in (0..n).map(|_| scan::<usize>()).enumerate() {
            idx[x] = i;
        }
        let (mut mn, mut mx) = (isize::MAX, isize::MIN);
        let mut ans = 0;
        for len in 1..=n {
            if len&1 == 1 {
                mn = mn.min(idx[len/2] as isize);
                mx = mx.max(idx[len/2] as isize);
            }
            let lm = (mx + 1 - len as isize).max(0);
            let rm = mn.min((n-len) as isize);
            if lm <= rm {
                ans += rm - lm + 1;
            }
        }
        writeln!(out, "{}", ans).unwrap();
    }
}