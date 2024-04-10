#![allow(dead_code)]

#[allow(unused_imports)]
use std::cmp::{max, min};
use std::io::*;

#[allow(unused_must_use)]
fn solve<W: Write>(sc: &mut Scanner, wr: &mut BufWriter<W>) {
    let a = sc.nchars();
    let n = a.len();
    if a[n - 1].to_digit(10).unwrap() % 2 == 0 {
        writeln!(wr, "0");
    } else if a[0].to_digit(10).unwrap() % 2 == 0 {
        writeln!(wr, "1");
    } else {
        let mut ok = false;
        for c in a {
            if c.to_digit(10).unwrap() % 2 == 0 {
                ok = true;
                break;
            }
        }
        if ok {
            writeln!(wr, "2");
        } else {
            writeln!(wr, "-1");
        }
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

    pub fn next(&mut self) -> String {
        assert!(self.has_tokens());
        return self.buf.pop().unwrap();
    }

    pub fn ni32(&mut self) -> i32 {
        return self.next().parse().ok().unwrap();
    }

    pub fn ni64(&mut self) -> i64 {
        return self.next().parse().ok().unwrap();
    }

    pub fn nf64(&mut self) -> f64 {
        return self.next().parse().ok().unwrap();
    }

    pub fn nchars(&mut self) -> Vec<char> {
        return self.next().chars().collect();
    }
}