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
    let mut bw = BufWriter::new(stdout());
    for _ in 0usize..scan() {
        let (n, c) : (i64, i64) = (scan(), scan());
        let mut a = [0i64; 101];
        for _ in 0..n {
            a[scan::<usize>()] += 1;
        }
        let mut ans: i64 = 0;
        for x in a {
            ans += if x < c { x } else { c };
        }
        writeln!(&mut bw, "{ans}");
    }
}