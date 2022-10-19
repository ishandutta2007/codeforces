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

#[derive(Default,Debug,Clone)]
struct Ans {
    tot: i64,
    pre: i64,
    suf: i64,
    max: i64,
}

fn solve(a: &[i64]) -> Vec<Ans>
{
    use std::cmp::*;
    if a.len() == 1 {
        let tmp = max(a[0], 0);
        return vec![Ans{ tot: a[0], pre: tmp, suf: tmp, max: tmp }];
    }
    let mid = a.len()/2;
    let l = solve(&a[..mid]);
    let r = solve(&a[mid..]);
    let mut ans = vec![Ans::default(); a.len()];
    for i in 0..mid {
        ans[i].tot = l[i].tot + r[i].tot;
        ans[i].pre = max(l[i].pre, l[i].tot + r[i].pre);
        ans[i].suf = max(r[i].suf, r[i].tot + l[i].suf);
        ans[i].max = max(max(l[i].max, r[i].max), l[i].suf + r[i].pre);

        ans[i + mid].tot = l[i].tot + r[i].tot;
        ans[i + mid].pre = max(r[i].pre, r[i].tot + l[i].pre);
        ans[i + mid].suf = max(l[i].suf, l[i].tot + r[i].suf);
        ans[i + mid].max = max(max(l[i].max, r[i].max), r[i].suf + l[i].pre);
    }
    ans
}

fn main()
{
    let lgn: usize = scan();
    let n = 1 << lgn;
    let a: Vec<i64> = (0..n).map(|_| scan()).collect();
    let b = solve(&a);
    //eprintln!("{:?}", b);
    let q: usize = scan();
    let mut x = 0usize;

    use std::io::*;
    let mut buf = BufWriter::new(stdout());
    for _ in 0..q {
        x ^= 1 << scan::<usize>();
        writeln!(buf, "{}", b[x].max).ok();
    }
}