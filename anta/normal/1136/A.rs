// This code is licensed under the terms of Apache-2.0 <http://www.apache.org/licenses/LICENSE-2.0> or MIT License <https://opensource.org/licenses/MIT>, at your choice.

use crate::comprog_lib::scanner::Scanner;
use std::io::{self, Read, Write};
pub fn solve<R: Read, W: Write>(read: R, out: &mut W) -> io::Result<()> {
    let mut sc = Scanner::from(read);
    let n = sc.usize();
    let chapters: Vec<_> = (0..n).map(|_| (sc.i32(), sc.i32())).collect();
    let k = sc.i32();
    let ans = chapters.into_iter().filter(|&(_, r)| k <= r).count();
    writeln!(out, "{}", ans)?;
    Ok(())
}
fn main() {
    let stdin = io::stdin();
    let mut stdout = io::BufWriter::new(io::stdout());
    solve(stdin.lock(), &mut stdout).unwrap_or_else(|e| {
        drop(stdout);
        writeln!(io::stderr(), "{}", e).ok();
        std::process::exit(1);
    });
}
mod comprog_lib {
    // comprog_lib-0.1.0
    pub mod scan_buf {
        use std::io::{self, Read};
        #[derive(Debug, Clone)]
        pub struct ScanBuf {
            buf: Vec<u8>,
            pos: usize,
            end: usize,
        }
        #[derive(Debug, Copy, Clone, Ord, PartialOrd, Eq, PartialEq, Hash)]
        pub struct ScanRange(pub usize, pub usize);
        impl ScanRange {
            pub fn slice(self, buf: &ScanBuf) -> &[u8] {
                &buf.buf[self.0..self.1]
            }
        }
        impl ScanBuf {
            pub fn new(initial_capacity: usize) -> Self {
                ScanBuf {
                    buf: vec![0; initial_capacity],
                    pos: 0,
                    end: 0,
                }
            }
            pub fn scan<R: Read, P: FnMut(u8) -> bool>(
                &mut self,
                mut reader: R,
                mut pred: P,
            ) -> io::Result<ScanRange> {
                let start = self.pos;
                loop {
                    if self.pos >= self.end {
                        if self.pos >= self.buf.len() {
                            let new_len = std::cmp::max(self.buf.len(), 1) * 2;
                            self.buf.resize(new_len, 0);
                        }
                        self.end += match reader.read(&mut self.buf[self.pos..]) {
                            Ok(0) => return Ok(ScanRange(start, self.pos)),
                            Ok(n) => n,
                            Err(ref e) if e.kind() == io::ErrorKind::Interrupted => 0,
                            Err(e) => return Err(e),
                        };
                    }
                    assert!(self.end <= self.buf.len());
                    while self.pos < self.end {
                        if pred(self.buf[self.pos]) {
                            return Ok(ScanRange(start, self.pos));
                        }
                        self.pos += 1;
                    }
                }
            }
        }
    }
    pub mod scanner {
        use crate::comprog_lib::scan_buf::{ScanBuf, ScanRange};
        use std::io::Read;
        #[derive(Debug, Clone)]
        pub struct Scanner<R> {
            pub reader: R,
            pub buf: ScanBuf,
        }
        impl<R: Read> From<R> for Scanner<R> {
            fn from(r: R) -> Self {
                Scanner {
                    reader: r,
                    buf: ScanBuf::new(8192),
                }
            }
        }
        impl<R: Read> Scanner<R> {
            pub fn scan<P: FnMut(u8) -> bool>(&mut self, pred: P) -> ScanRange {
                self.buf.scan(&mut self.reader, pred).unwrap()
            }
            fn digits(&mut self) -> (bool, &[u8]) {
                self.scan(|b| b' ' < b);
                let mut negative = false;
                self.scan(|b| b != b'-' || std::mem::replace(&mut negative, true));
                let digits = self.scan(|b| b < b'0' || b'9' < b);
                (negative, digits.slice(&self.buf))
            }
        }
        macro_rules! impl_scan_int { ($($name:ident),*) => { impl<R: Read> Scanner<R> { $(       #[allow(unused)] pub fn $name(&mut self) -> $name { let (neg, digits) = self.digits(); if !neg { digits.iter().fold($name::default(), |x, b| x * 10 + $name::from(b - b'0')) } else { digits.iter().fold($name::default(), |x, b| x * 10 - $name::from(b - b'0')) } } )* } } }
        impl_scan_int!(u32, i32, u64, i64, usize);
    }
}