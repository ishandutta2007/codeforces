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

fn solve() -> f64
{
    let n: usize = scan();
    let vec: Vec<i64> = (0..n).map(|_| scan()).collect();
    let vec: Vec<(i64, i64)> = vec.into_iter().zip((0..n).map(|_| scan::<i64>())).collect();
    let (mut l, mut r) = (0f64, 1e8f64);
    for i in 0..50 {
        let mid = (l + r)/2f64;
        let (mut mxl, mut mnr) = (0f64, 1e8f64);
        for &(x, t) in &vec {
            mxl = mxl.max(x as f64 - (mid - t as f64));
            mnr = mnr.min(x as f64 + (mid - t as f64));
        }
        if mxl <= mnr { r = mid } else { l = mid };
        if i == 49 {
            return (mxl + mnr)/2f64;
        }
    }
    -1f64
}

fn main()
{
    use std::io::*;
    let mut bw = BufWriter::new(stdout());
    for _ in 0usize..scan() {
        writeln!(bw, "{}", solve());
    }
}