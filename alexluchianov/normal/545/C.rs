use std::io;
use std::cmp;

fn main() {
  let mut n = String::new();
  io::stdin().read_line(&mut n).expect("Failed to read line");
  let n :i32 = n.trim().parse().expect("Expected integer");
  
  let mut v: Vec<(i32,i32)> = Vec::new();

  for _i in 0..=n-1 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let x:i32;
    let y:i32;
    let aux :Vec<i32> = input.trim().split(' ')
                      .map(|val| val.parse().expect("expected integer"))
                      .collect();
    x = aux[0];
    y = aux[1];
    v.push((x, y));
  }
  let mut dp: Vec<(i32,i32)> = vec![(0, 0); n as usize];
  dp[0].0 = 1;
  dp[0].1 = 1;
  
  let mut i :usize = 1;
  while i < (n as usize) {
    dp[i].0 = cmp::max(dp[i - 1].0, dp[i - 1].1);
    if v[i].1 < v[i].0 - v[i - 1].0 {
      dp[i].0 = cmp::max(dp[i].0, dp[i - 1].0 + 1);
    }
    if v[i].1 + v[i - 1].1 < v[i].0 - v[i - 1].0 {
      dp[i].0 = cmp::max(dp[i].0, dp[i - 1].1 + 1);
    }
    if i == (n - 1) as usize || v[i].1 < v[i + 1].0 - v[i].0 {
      dp[i].1 = cmp::max(dp[i - 1].0, dp[i - 1].1) + 1;
    }
    i = i + 1;
  }
  println!("{}", dp[n as usize - 1].1);
}