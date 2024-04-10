use std::io;

struct Inparser{
  aux: Vec<i32>,
  ptr: usize,
}

impl Inparser{
  fn reset_buffer(&mut self) {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).expect("Failed to read line");
    
    self.aux = buffer.trim()
              .split(' ')
              .map(|x| x.parse().expect("Expected integer"))
              .collect();

    self.ptr = 0;
  }

  fn read(&mut self, n : &mut i32) {
    if self.ptr == self.aux.len() {
      self.reset_buffer();
    }
    let x = self.aux[self.ptr];
    *n = x;
    self.ptr = self.ptr + 1;
  }
}

fn main() { 
  let mut input = Inparser {
    aux: Vec::new(),
    ptr: 0,
  };

  let mut t = 0;
  input.read(&mut t);
  for _testcase in 0..t {
    let mut n = 0;
    let mut target = 0;
    input.read(&mut n);
    input.read(&mut target);
    target = target - 1;
    let mut frec :i32 = 0;

    for _edge in 0..n-1 {
      let mut x = 0;
      let mut y = 0;
      input.read(&mut x);
      input.read(&mut y);
      x = x - 1;
      y = y - 1;
      if x == target {
        frec += 1;
      }
      if y == target {
        frec += 1;
      }
    }
    if frec <= 1{
      println!("Ayush");
    } else {
      if n % 2 == 0 {
        println!("Ayush");
      } else {
        println!("Ashish");
      }
    }
  }
}