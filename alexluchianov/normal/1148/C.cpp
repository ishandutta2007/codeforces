#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[1 + nmax];

vector<pair<int,int>> op;

void simpleswap(int x, int y){
  swap(v[x], v[y]);
  op.push_back({x, y});
}

void advancedswap(int x, int y, int n){
  if(x == y)
    return ;
  else if(n / 2 <= fabs(y - x))
    simpleswap(x, y);
  else
    if(x <= n / 2) {
      simpleswap(x, n);
      advancedswap(y, n, n);
      simpleswap(x, n);
    } else {
      simpleswap(x, 1);
      advancedswap(y, 1, n);
      simpleswap(x, 1);
    }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n ; i++)
    cin >> v[i];

  for(int i = 1;i <= n; i++)
    while(v[i] != i)
      advancedswap(i, v[i], n);

  cout << op.size() << '\n';
  for(int i = 0; i < op.size(); i++)
    cout << op[i].first << " " << op[i].second << '\n';

  return 0;
}