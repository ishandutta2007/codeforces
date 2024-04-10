use std::io;

fn main() {
  let mut n = String::new();

  io::stdin().read_line(&mut n).expect("Failed to read line");
  let n :i32 = n.trim().parse().expect("Expected integer");
  let mut result = 0;

  for _i in 0..n {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let input  = input.trim();
    match input {
      "++X" => result = result + 1,
      "X++" => result = result + 1,
      "--X" => result = result - 1,
      "X--" => result = result - 1,
      _ => continue,
    }
  }
  println!("{}", result);
}