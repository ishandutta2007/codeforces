use std::io;

fn upper(x : char) -> char {
  match x {
    'a'..='z' => (x as u8 - 'a' as u8 + 'A' as u8) as char,
    _ => x,
  }
}

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read input");
  input = input.trim().to_string();
  
  let mut sol = String::new();
  let mut steps = 0;

  for ch in input.chars() {
    if steps == 0 {
      sol = sol + &String::from(upper(ch));
    } else {
      sol = sol + &String::from(ch);
    }
    steps = steps + 1;
  }
  println!("{}", sol);
}