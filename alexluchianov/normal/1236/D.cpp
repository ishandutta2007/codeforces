#include <iostream>
#include <set>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
set<int> lin[1 + nmax], col[1 + nmax];

ll solve(int x, int y, int x2, int y2){
  ll step = 0;

  if(!(x <= x2 && y <= y2))
    return step;

  int ynext = MIN(y2, *lin[x].lower_bound(y) - 1);

  y2 = ynext;

  int mv = ynext - y + 1;
  if(mv == 0)
    return step;
  step += mv;

  int xnext = MIN(x2, *col[y2].lower_bound(x) - 1);
  mv = xnext - x;
  if(mv == 0)
    return step;
  step += mv;
  x++;
  x2 = xnext;

  set<int>::iterator it = lin[x2].upper_bound(y2);
  it--;
  ynext = MAX(y, *it + 1);
  mv = y2 - ynext;
  if(mv == 0)
    return step;
  step += mv;
  y = ynext;
  y2--;


  it = col[y].upper_bound(x2);
  it--;
  xnext = MAX(x, *it + 1);
  mv = x2 - xnext;
  if(mv == 0)
    return step;
  step += mv;
  x = xnext;
  x2--;

  return step + solve(x, y + 1, x2, y2);
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1;i <= n; i++) {
    lin[i].insert(0);
    lin[i].insert(m + 1);
  }
  for(int i = 1;i <= m; i++){
    col[i].insert(0);
    col[i].insert(n + 1);
  }
  for(int i = 1;i <= k; i++){
    int x, y;
    cin >> x >> y;
    lin[x].insert(y);
    col[y].insert(x);
  }

  if(1LL * n * m - k == solve(1, 1, n, m))
    cout << "Yes";
  else
    cout << "No";

  return 0;
}
/*
3 3 1
2 2
*/