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
        let n = scan::<usize>();
        let mut cnt2 = (0..n).map(|_| scan::<u64>().trailing_zeros())
                             .fold(0, |x, y| x+y);
        let mut vec: Vec<_> = (1..=n).map(|x| x.trailing_zeros()).collect();
        vec.sort();
        while cnt2 < n as _ {
            if let Some(x) = vec.pop() {
                cnt2 += x;
            } else {
                break;
            }
        }
        writeln!(out, "{}", if cnt2 >= n as _ { (n - vec.len()) as i32 } else { -1 }).unwrap();
    }
}