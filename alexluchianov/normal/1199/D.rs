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
  input.read(&mut n);
  let mut v = vec![(0, 0);n as usize];
  
  for i in 0..n {
    input.read(&mut v[i as usize].0);
  }

  let mut q = 0;
  input.read(&mut q);
  let mut modifier = vec![0;q as usize];

  for i in 0..q {
    let mut op = 0;
    input.read(&mut op);
    if op == 1 {
      let mut pos = 0;
      let mut val = 0;
      input.read(&mut pos);
      input.read(&mut val);
      pos = pos - 1;
      v[pos as usize] = (val, i);
    } else {
      input.read(&mut modifier[i as usize]);
    }
  }

  for i in (0..q - 1).rev() {
    modifier[i as usize] = std::cmp::max(modifier[i as usize], modifier[i as usize + 1]);
  }

  for i in 0..n {
    print!("{} ", std::cmp::max(v[i as usize].0, modifier[v[i as usize].1 as usize]));
  }
}