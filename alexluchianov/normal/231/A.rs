use std::io;

fn main() {
  let mut n = String::new();
  io::stdin().read_line(&mut n).expect("Failed to read input");
  let n :usize = n.trim().parse().expect("Expected integer");
  
  let mut result :i32 = 0;

  for _i in 0..n {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let v: Vec<i32> = input.trim().split(" ").map(|x| x.parse().expect("Expected integer")).collect();
    let sum = v[0] + v[1] + v[2];
    if 1 < sum {
      result = result + 1;
    }
  }
  println!("{}", result);
}