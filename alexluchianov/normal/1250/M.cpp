#include <iostream>
#include <vector>

using ll = long long;

int const sigma = 10;
int mat[1 + sigma][1 + sigma];
int pos[1 + sigma];

int const t = 7, c = 5;

void read() {
  /*
     for(int i = 0; i < sigma; i++)
     for(int j = 0; j < sigma; j++)
     mat[i][j] = (pos[i] == pos[j]);
   */
  //*
  for(int i = 0; i < sigma; i++)
    for(int j = 0; j < sigma; j++)
      mat[i][j] = 0;

  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    for(int j = 0; j < s.size(); j++)
      for(int h = 0; h < s.size(); h++)
        if(j != h)
          mat[s[j] - '0'][s[h] - '0'] = 1;
  }
  //*/

}

int steps = 0;
void makemove(std::vector<int> sol) {
  ++steps;
  /*
     for(int i = 0; i < sol.size(); i++) {
     int node = sol[i];
     pos[node]++;
     if(pos[node] == (t + c))
     pos[node] = t;
     }
  //*/

  //*
  std::cout << "next ";
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << std::endl;
  //*/
}

int main() {
  //phase 1
  while(true) {
    if(steps % 2 == 0) {
      makemove({0});
    } else if(steps % 2 == 1) {
      makemove({0, 1});
    }
    read();
    if(mat[0][1] == 1)
      break;
  }
  //phase 2
  while(true) {
    makemove({2, 1});
    read();
    if(mat[0][1] == 1)
      break;
  }
  //phase 3
  while(true) {
    if(mat[0][2] == 1)
      makemove({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    else
      makemove({2, 3, 4, 5, 6, 7, 8, 9});
    read();
    if(mat[2][9] == 1) {
      while(mat[0][2] == 0) {
        makemove({0, 1});
        read();
      }
      std::cout << "done " << std::endl;
      break;
    }
  }

  return 0;
}