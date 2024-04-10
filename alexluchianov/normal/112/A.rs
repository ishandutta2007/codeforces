use std::io;
use std::cmp::Ordering;

fn main() {
  let mut s1 = String::new();
  io::stdin().read_line(&mut s1).expect("Failed to read line");
  let mut s2 = String::new();
  io::stdin().read_line(&mut s2).expect("Failed to read line");
  s1 = s1.to_lowercase();
  s2 = s2.to_lowercase();
  match s1.cmp(&s2) {
    Ordering::Less => println!("{}", -1),
    Ordering::Greater => println!("{}", 1),
    Ordering::Equal => println!("{}", 0),
  }
}