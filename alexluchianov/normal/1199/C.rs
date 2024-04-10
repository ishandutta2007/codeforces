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
  let mut lim = 0;
  input.read(&mut n);
  input.read(&mut lim);
  let mut v = vec![0;n as usize];
  for i in 0..n {
    input.read(&mut v[i as usize]);
  }
  let mut k: i32 = 0;
  while (k + 1) * n <= lim * 8{
    k = k + 1;
  }

  v.sort();
  let mut v2: Vec<(i32, i32)> = Vec::new();

  for it in v {
    if 0 == v2.len() {
      v2.push((it, 1));
    } else if v2[v2.len() - 1].0 == it {
      let ptr: usize = v2.len();
      let val = v2[ptr - 1].1 + 1;
      v2[ptr - 1].1 = val;
    } else { 
      v2.push((it, 1));
    }
  }
  
  let mut sum: i32 = 0;

  v = v2.iter().map(|x| {sum += x.1; sum}).collect(); 
  
  k = std::cmp::min(k, 30);

  if v.len() <= (1 << k) {
    println!("{}", 0);
  } else {
    let mut result = v[(1 << k) as usize - 1];
    for i in (1 << k) as usize..v.len() {
      result = std::cmp::max(result, v[i] - v[i - (1 << k) as usize]);
    }
    println!("{}", n - result);
  }
}