#[allow(unused_imports)]
use std::io::*;
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn ask(x: i32, y: i32) -> i32
{
    println!("? {} {}", x+1, y+1);
    let mut s = String::new();
    stdin().read_line(&mut s).ok();
    s.trim().parse().unwrap()
}

fn advance(a: Vec<i32>) -> Vec<i32>
{
    if a.len() == 2 {
        match ask(a[0], a[1]) {
            1 => return vec![a[0]],
            2 => return vec![a[1]],
            _ => panic!(),
        }
    }
    let mut ans = vec![];
    for i in (0..a.len()).step_by(4) {
        ans.push(match ask(a[i+0], a[i+2]) {
            0 => if ask(a[i+1], a[i+3]) == 1 { a[i+1] } else { a[i+3] },
            1 => if ask(a[i+0], a[i+3]) == 1 { a[i+0] } else { a[i+3] },
            2 => if ask(a[i+1], a[i+2]) == 1 { a[i+1] } else { a[i+2] },
            _ => panic!(),
        });
    }
    ans
}

fn main()
{
    let mut scan = Scanner::default();
    let mut _out = BufWriter::new(stdout());
    let t: i32 = scan.next();
    for _ in 0..t {
        let n: i32 = scan.next();
        let mut ans: Vec<i32> = (0..1<<n).collect();
        while ans.len() > 1 {
            ans = advance(ans);
        }
        println!("! {}", ans[0]+1);
    }
}