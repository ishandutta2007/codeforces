use std::io;

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  let n :i32 = input.trim().parse().expect("Input is not integer");
  
  input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  
  let v: Vec<i32> = input.trim()
                  .split(" ").map(|x| x.parse().expect("Expected integer")).collect();

  if v.len() != n as usize {
    panic!("Wrong amount of integers");
  }
  
  let mut p : Vec<i32> = vec![0; n as usize];
  let mut ptr:i32 = 0;
  for val in v.iter() {
    ptr += 1;
    p[*val as usize - 1] = ptr;
  }
  for val in p.iter() {
    print!("{} ", val);
  }
  println!();

}