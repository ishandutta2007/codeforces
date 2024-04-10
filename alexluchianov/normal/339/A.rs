use std::io;

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  input = input.trim().to_string();
  let mut v:Vec<i32> = 
    input.split("+")
      .map(|x| x.parse().expect("Input is not integer"))
        .collect();
  v.sort();
  let mut output = String::new();
  let mut steps = 0;
  for val in v {
    if 0 < steps {
      output.push_str("+");
    }
    output.push_str(&val.to_string());
    steps = steps + 1
  }
  println!("{}", output);
}