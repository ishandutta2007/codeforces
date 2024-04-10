use std::io;

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read input");
  let n :usize = input.trim().parse().expect("Expected integer");
  
  input = String::new();

  io::stdin().read_line(&mut input).expect("Failed to read line");
  let input = input.trim();
  
  let l = 10;
  let mut rooms = vec![0;l];

  for i in input.chars(){
    match i {
      'L' => {
        for j in (0..l) {
          if(rooms[j] == 0) {
            rooms[j] = 1;
            break ;
          }
        }
      }
      'R' => {
        for j in (0..l).rev() {
          if(rooms[j] == 0) {
            rooms[j] = 1;
            break;
          }
        }
      }
      x => {
            rooms[x.to_digit(10).expect("Expected digit") as usize] = 0},
    }
  }

  for i in (0..l) {
    print!("{}", rooms[i]);
  }
}