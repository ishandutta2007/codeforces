use std::io;

fn main() {
  let mut n = String::new();
  io::stdin().read_line(&mut n).expect("Failed to read line");
  n = n.trim().parse().expect("Input is not integer");
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  input = input.trim().to_string();
  let mut last :char = 'X';
  let mut result: usize = 0;
  for i in input.chars() {
    if last != i {
      last = i;
      result = result + 1;
    }
  }
  println!("{}", input.len() - result);
}