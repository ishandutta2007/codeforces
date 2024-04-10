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
  let mut x = 0;
  let mut y = 0;
  input.read(&mut x);
  input.read(&mut y);
  let x = x as f64;
  let y = y as f64;
  let result : f64 = ((y*y)- (x * x) ) / (2.0 * x);
  println!("{:.10}", result);
}