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

fn make2(a: &mut Vec<i32>)
{
    let p2 = 1usize << (usize::BITS - a.len().leading_zeros() - 1);
    if p2 == a.len() {
        return;
    }
    let mut b: Vec<i32> = a[p2..].to_vec();
    for i in 0..a.len()-p2 {
        b[i] ^= a[i];
    }
    make2(&mut b);
    for i in a.len()..2*p2 {
        a.push(a[i - p2] ^ b[i % b.len()]);
    }
}

fn xos(a: &mut Vec<i32>)
{
    let bits = a.len().trailing_zeros();
    for bit in (0..bits).map(|x| 1<<x) {
        for i in 0..a.len() {
            if (i & bit) != 0 {
                a[i] ^= a[i ^ bit];
            }
        }
    }
}

fn main()
{
    let n: usize = scan();
    let mut a: Vec<i32> = (0..n).map(|_| scan()).collect();
    make2(&mut a);
    a.reverse();
    xos(&mut a);
    a.resize(n, 0);
    a.reverse();
    for x in a {
        print!("{} ", x);
    }
    println!( "");
}