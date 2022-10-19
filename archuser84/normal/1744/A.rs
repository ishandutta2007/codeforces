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
    for _ in 0..scan::<usize>() {
        let n: usize = scan();
        let v: Vec<i32> = (0..n).map(|_| scan()).collect();
        let s: Vec<u8> = Vec::<u8>::from(scan::<String>().as_bytes());
        let mut a: Vec<u8> = vec![0; 100];
        let mut ans = true;
        for (i, &x) in v.iter().enumerate() {
            let x = x as usize;
            if a[x] == 0 {
                a[x] = s[i];
            }
            if a[x] != s[i] {
                ans = false;
                break;
            }
        }
        println!("{}", if ans { "YES" } else { "NO" });
    }
}