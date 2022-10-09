use std::io;
 
struct Inparser{
  aux: Vec<i32>,
  ptr: usize,
}
 
impl Inparser{
  fn reset_buffer(&mut self) {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    self.aux = input.trim().split(' ')
          .map(|x| x.parse().expect("Expected integer"))
          .collect();
    self.ptr = 0;
  }
  fn read(&mut self, n : &mut i32) {
    if self.ptr == self.aux.len() {
      self.reset_buffer();
    }
    *n = self.aux[self.ptr];
    self.ptr += 1;
  }
}

fn main() {
  let mut input = Inparser{
    aux: Vec::new(),
    ptr: 0,
  };
  let mut n = 0;
  let mut x = 0;
  let mut y = 0;
  input.read(&mut n);
  input.read(&mut x);
  input.read(&mut y);
  let n = n as usize;
  let y = y as usize;
  let x = x as usize;

  let mut v: Vec<i32> = vec![0;n];

  for i in (0..n) {
    input.read(&mut v[i]);
  }
  
  let mut sol : Option<usize> = None;

  for i in (0..n) {
    let mut bigger: bool = true;
    for j in (1..=x) {
      if j <= i && v[i - j] < v[i] {
        bigger = false;
      }
    }
    for j in (1..=y) {
      if i + j < n && v[i + j] < v[i] {
        bigger = false;
      }
    }
    sol = match sol {
      Some(x) => Some(x),
      None => {
        match bigger {
          true => Some(i),
          false => None,
        }
      },
    };
  }
  println!("{}", 1 + sol.expect("Failed to find answer"));
}