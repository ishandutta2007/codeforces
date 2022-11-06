#![allow(dead_code)]

#![allow(unused_imports)]
use std::cmp::{max, min};
use std::io::*;
use std::collections::*;

#[allow(unused_must_use)]
fn solve<W: Write>(sc: &mut Scanner, wr: &mut BufWriter<W>) {
    let n = sc.nusize();
    let a: Vec<i32> = sc.nvec(n);
    if a[0] == n as i32 {
        for i in 1..n {
            write!(wr, "{} ", a[n - i]);
        }
        writeln!(wr, "{}", a[0]);
    } else if a[n - 1] == n as i32 {
        for i in 1..n {
            write!(wr, "{} ", a[n - 1 - i]);
        }
        writeln!(wr, "{}", a[n - 1]);
    } else {
        writeln!(wr, "-1");
    }
}

#[allow(unused_variables)]
fn main() {
    let args: Vec<String> = std::env::args().collect();
    let stdin = std::io::stdin();
    let mut sc = if args.len() <= 1 {
        Scanner::new(ScReader::FromStdin(BufReader::new(stdin.lock())))
    } else {
        Scanner::new(ScReader::FromFile(BufReader::new(std::fs::File::open(args[1].clone()).unwrap())))
    };
    let stdout = std::io::stdout();
    let mut wr = BufWriter::new(stdout.lock());
    let t = 1;
    let t = sc.ni32();
    for i in 1..=t {
        solve(&mut sc, &mut wr);
    }
}

enum ScReader<'a> {
    FromStdin(BufReader<StdinLock<'a>>),
    FromFile(BufReader<std::fs::File>),
}

struct Scanner<'a> {
    reader: ScReader<'a>,
    buf: Vec<String>,
}

impl<'a> Scanner<'a> {
    pub fn new(reader: ScReader<'a>) -> Self {
        Self {
            reader: reader,
            buf: vec![],
        }
    }

    pub fn has_tokens(&mut self) -> bool {
        while self.buf.len() == 0 {
            let mut s = String::new();
            let res = match &mut self.reader {
                ScReader::FromStdin(r) => r.read_line(&mut s),
                ScReader::FromFile(r) => r.read_line(&mut s),
            };
            if res.is_err() {
                break;
            }
            self.buf = s.split_ascii_whitespace().rev().map(String::from).collect();
        }
        return self.buf.len() > 0;
    }

    pub fn next<T: std::str::FromStr>(&mut self) -> T {
        assert!(self.has_tokens());
        return self.buf.pop().unwrap().parse().ok().unwrap();
    }

    pub fn ns(&mut self) -> String { self.next() }
    pub fn ni32(&mut self) -> i32 { self.next() }
    pub fn ni64(&mut self) -> i64 { self.next() }
    pub fn nf64(&mut self) -> f64 { self.next() }
    pub fn nusize(&mut self) -> usize { self.next() }

    pub fn nchars(&mut self) -> Vec<char> {
        return self.ns().chars().collect();
    }

    pub fn nvec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        return (0..n).map(|_| self.next()).collect();
    }
}

trait Kek {
    fn kek1(&self) -> i32;
}

trait Kek2 {
    fn kek(&mut self) -> i32;
}

impl Kek for Vec<i32> {
    fn kek1(&self) -> i32 { 1 }
}

impl Kek2 for Vec<i32> {
    fn kek(&mut self) -> i32 { 2 }
}