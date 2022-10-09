use std::io;

fn getmin(a :i32, b :i32) -> i32 {
  if a < b {
    a
  } else {
    b
  }
}

fn main() {
  let mut n = String::new();
  io::stdin().read_line(&mut n).expect("Failed to read line"); 
  let n :i32 = n.trim().parse().expect("Expected integer");

  let mut frec = vec![0; 5];

  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  let v : Vec<usize> = 
    input.trim().split(' ')
      .map(|x| x.parse().expect("Expected integer"))
        .collect();
  for it in v {
    frec[it] += 1;
  }

  let mut result :i32 = frec[4];
  let val = getmin(frec[1], frec[3]);

  frec[1] -= val;
  frec[3] -= val;
  result += val + (frec[1] + frec[2] * 2 + 3) / 4 + frec[3];
  println!("{}", result);
}