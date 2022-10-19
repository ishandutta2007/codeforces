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
        let (n, q): (usize, usize) = (scan(), scan());
        let mut cnt = [0, 0];
        let mut sum = [0, 0];
        for x in (0..n).map(|_| scan::<usize>()) {
            cnt[x%2] += 1;
            sum[x%2] += x;
        }
        for _ in 0..q {
            let (t, x): (usize, usize) = (scan(), scan());
            if x&1 == 1 {
                cnt[t^1] += cnt[t];
                sum[t^1] += sum[t] + x * cnt[t];
                cnt[t] = 0;
                sum[t] = 0;
            } else {
                sum[t] += cnt[t] * x;
            }
            writeln!(out, "{}", sum[0] + sum[1]).unwrap();
        }
    }
}