use std::io;
use std::collections::HashMap;

fn main() {
  let mut n = String::new();
  io::stdin().read_line(&mut n).expect("Failed to read line");
  let n :i32 = n.trim().parse().expect("Failed to read integer");

  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  let v: Vec<i32> = input.trim().split(' ')
                    .map(|x| x.parse().expect("Failed to read integer"))
                    .collect();
  
  let mut dp = vec![0; n as usize];
  let mut last = vec![0; n as usize];
  let mut frec = HashMap::new();
  let mut lastmet = HashMap::new();

  let mut bestid = 0;
  
  for i in 0..n {
    let val : i32 = v[i as usize] - 1;

    match frec.get(&val) {
      None => {
        dp[i as usize] = 1;
        last[i as usize] = -1;
      }
      Some(x) => {
        dp[i as usize] = *x+ 1;
        last[i as usize] = *lastmet.get(&val).unwrap();
      }
    }
    let val = v[i as usize];
    match frec.get(&val) {
      None => {
        frec.insert(v[i as usize], dp[i as usize]);
      }
      Some(x) => {
        if *x < dp[i as usize] {
          frec.insert(v[i as usize], dp[i as usize]);
        }
      }
    }
    if dp[bestid as usize] < dp[i as usize] {
      bestid = i;
    }
    lastmet.insert(v[i as usize], i);
  }

  let mut sol :Vec<i32> = Vec::new();
  while 0 <= bestid {
    sol.push(bestid);
    bestid = last[bestid as usize];
  }
  sol = sol.iter().rev().cloned().collect();
  println!("{}", sol.len());
  for val in sol {
    print!("{} ", val + 1);
  }
}