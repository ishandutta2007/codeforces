use std::io;

fn sub(n :i32) -> i32{
  if n % 10 == 0 {
    return n / 10;
  } else {
    return n - 1;
  }
}

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  let inputs: Vec<i32>  = input
  .trim().split(" ").map(|x| x.parse().expect("Not an integer")).collect();
  let mut n:i32 = inputs[0];
  let k:i32 = inputs[1];
  for _i in 0..k {
    n = sub(n);
  }

  println!("{}\n", n);
}