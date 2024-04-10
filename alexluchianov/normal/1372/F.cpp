#include <iostream>
#include <cmath>
#include <cassert>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];

std::pair<int,int> ask(int x, int y) {
  std::cout << "? " << x << " " << y << '\n';
  std::cout << std::flush;
  int answer, answer2;
  std::cin >> answer >> answer2;
  return {answer, answer2};
}

void imprint(int x, int y, int val){
  for(int i = x;i <= y; i++)
    v[i] = val;
}

void solve(int x, int y) {
  if(v[x] == v[y]) {
    imprint(x, y, v[x]);
    return ;
  }
  std::pair<int,int> curr = ask(x, y);
  if(curr.first == v[x]) {
    imprint(x, x + curr.second - 1, v[x]);
    v[x + curr.second] = ask(x + curr.second, x + curr.second).first;
    solve(x + curr.second, y);
  } else if(curr.first == v[y]) {
    imprint(y - curr.second + 1, y, v[y]);
    v[y - curr.second] = ask(y - curr.second, y - curr.second).first;
    solve(x, y - curr.second);
  } else {
    v[x + curr.second] = ask(x + curr.second, x + curr.second).first;
    solve(x, x + curr.second);
    solve(x + curr.second, y);
  }
}

int main() {
  int n;
  std::cin >> n;
  v[1] = ask(1, 1).first;
  v[n] = ask(n, n).first;
  solve(1, n);
  std::cout << "! ";
  for(int i = 1;i <= n; i++)
    std::cout << v[i] << " ";
  std::cout << '\n';
  return 0;
}