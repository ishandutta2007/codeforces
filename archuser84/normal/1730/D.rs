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
    let n = scan::<usize>();
    let (s, t) = (scan::<String>().as_bytes().to_vec(), scan::<String>().as_bytes().to_vec());
    let mut dard = std::collections::HashSet::<(u8, u8)>::new();
    for i in 0..n {
        let tmp = (s[i], t[n-1-i]);
        if dard.contains(&tmp) {
            dard.remove(&tmp);
        } else if dard.contains(&(tmp.1, tmp.0)) {
            dard.remove(&(tmp.1, tmp.0));
        } else {
            dard.insert(tmp);
        }
    }
    if dard.len() > 1 { return "NO".to_string(); }
    if let Some((x, y)) = dard.iter().next() {
        if x != y { return "NO".to_string(); }
    }
    return "YES".to_string();
}

fn main()
{
    use std::io::*;
    let mut bw = BufWriter::new(stdout());
    for _ in 0usize..scan() {
        writeln!(bw, "{}", solve());
    }
}