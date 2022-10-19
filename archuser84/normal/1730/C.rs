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

fn solve() -> String
{
    let s = scan::<String>();
    let mut v = Vec::<u8>::new();
    let mut bag = Vec::<u8>::new();
    for &x in s.as_bytes() {
        while v.len() > 0 && *v.last().unwrap() > x {
            bag.push((v.pop().unwrap() + 1).min(b'9'));
        }
        v.push(x);
    }
    bag.sort();
    while let (Some(a), Some(b)) = (v.last(), bag.first()) {
        if a <= b { break; }
        bag.push(*a);
        v.pop();
    }
    bag.sort();
    v.append(&mut bag);
    String::from(std::str::from_utf8(&v).unwrap())
}

fn main()
{
    use std::io::*;
    let mut bw = BufWriter::new(stdout());
    for _ in 0usize..scan() {
        writeln!(bw, "{}", solve());
    }
}