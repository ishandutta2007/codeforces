use std::io;

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  let input = String::from(input.trim());
  let mut verdict :bool = false;
  let mut last : i32 = 0;
  let mut acc : i32 = 0;
  
  for it in input.bytes() {
    if it == b'0' {
      if last == 0 {
        acc = acc + 1;
      } else {
        last = 0;
        acc = 1;
      }
    } else {
      if last == 1 {
        acc = acc + 1;
      } else {
        last = 1;
        acc = 1;
      }
    }

    if 7 <= acc {
      verdict = true;
    }
  }

  if verdict == true {
    println!("YES");
  } else {
    println!("NO");
  }
}