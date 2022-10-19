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

fn solve(a: Vec<u32>, b: Vec<u32>) -> u32
{
    let mut v = vec![(a, b)];
    let mut ans = 0u32;
    'bit_loop: for bit in (0u32..32).map(|x| 1 << x).rev() {
        let mut v2 = vec![];
        for (x, y) in &v {
            let (xz, xo): (Vec<_>, Vec<_>) = x.iter().partition(|&&x| x & bit == 0);
            let (yz, yo): (Vec<_>, Vec<_>) = y.iter().partition(|&&x| x & bit == 0);
            if xo.len() != yz.len() {
                continue 'bit_loop;
            }
            if !xz.is_empty() { v2.push((xz, yo)); }
            if !xo.is_empty() { v2.push((xo, yz)); }
        }
        ans ^= bit;
        v = v2;
    }
    ans
}

fn main()
{
    use std::io::*;
    let mut out = BufWriter::new(stdout());
    let t: u32 = scan();
    
    for _ in 0..t {
        let n: u32 = scan();
        let a: Vec<u32> = (0..n).map(|_| scan()).collect();
        let b: Vec<u32> = (0..n).map(|_| scan()).collect();
        writeln!(out, "{}", solve(a, b)).ok();
    }
    out.flush().ok();
}