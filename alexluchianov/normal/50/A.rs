use std::io;

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  
  input = input.trim().to_string();

  let v: Vec<i32> = 
    input.split(" ")
      .map(|x| x.parse().expect("Not an integer"))
      .collect();

  let result = v[0] * v[1] / 2;
  println!("{}", result);
}