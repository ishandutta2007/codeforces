#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 50;

struct Block{
  int x;
  int y;
  int x2;
  int y2;
  ll cost;
  bool operator < (Block const &a) const{
    return cost < a.cost;
  }
};

vector<Block> sol;

bool valid(int x, int y){
  return (1 <= x && x <= nmax) && (1 <= y && y <= nmax);
}

void addblock(int x, int y, int x2, int y2, ll cost){
  if(valid(x, y) && valid(x2, y2))
    sol.push_back({x, y, x2, y2, cost});
}

int main()
{
  ll paths;
  cin >> paths;
  int n, m;
  n = m = nmax;
  ll coef = 1;
  cout << n << " " << m << '\n';

  for(int i = 1; i <= nmax - 3; i += 2){
    addblock(i, i + 2, i, i + 3, coef);
    addblock(i, i + 3, i, i + 4, 0);
    addblock(i - 1, i + 3, i - 1, i + 4, 0);

    addblock(i + 1, i + 2, i + 1, i + 3, coef * 3);
    addblock(i + 2, i, i + 3, i, coef);
    addblock(i + 2, i + 1, i + 3, i + 1, 0);

    addblock(i + 3, i, i + 4, i, 0);
    addblock(i + 3, i - 1, i + 4, i - 1, 0);

    addblock(i, i + 1, i - 1, i + 1, 0);
    addblock(i, i + 2, i - 1, i + 2, 0);

    addblock(i + 1, i, i + 1, i - 1, 0);
    addblock(i + 2, i, i + 2, i - 1, 0);

    coef = coef * 6;
  }
  addblock(nmax - 1, nmax - 1, nmax - 1, nmax, 0);
  addblock(nmax - 1, nmax - 1, nmax, nmax - 1, 0);
  sort(sol.begin(), sol.end());
  vector<Block> newsol;

  for(int i = sol.size() - 1; 0 <= i; i--){
    if(0 < sol[i].cost && sol[i].cost <= paths) {
      paths -= sol[i].cost;
    } else
      newsol.push_back(sol[i]);
  }

  cout << newsol.size() << '\n';
  for(int i = 0; i < newsol.size(); i++) {
    if(newsol[i].x2 + newsol[i].y2 < newsol[i].x + newsol[i].y) {
      swap(newsol[i].x2, newsol[i].x);
      swap(newsol[i].y2, newsol[i].y);
    }
    cout << newsol[i].x << " " << newsol[i].y << " " << newsol[i].x2 << " " << newsol[i].y2 << '\n';
  }
  return 0;
}