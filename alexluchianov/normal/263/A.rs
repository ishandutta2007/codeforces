use std::io;

fn abs(x :i32) -> i32 {
  if x < 0 {
    return -x;
  } else {
    return x;
  }
}
fn main() {
  let mut result : i32 = 0;
  for i in 0..5 {
    let mut v = String::new();
    io::stdin().read_line(&mut v).expect("Failed to read line");

    let v: Vec<i32> = v.trim().split(" ")
      .map(|x| x.parse().expect("pls number"))
      .collect();
    let mut j = 0;
    for num in v {
      if num == 1 {
        result = abs(j - 2) + abs(i - 2);
      }
      j = j + 1;
    }
  }
  println!("{}", result);
}