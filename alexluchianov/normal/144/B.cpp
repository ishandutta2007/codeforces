#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ld = long double;
using ll = long long;

int const nmax = 10000;
int seen[1 + nmax];

int dist(int x, int y, int x2, int y2){
  return (x - x2) * (x - x2) + (y - y2) * (y - y2);
}

int main()
{
  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  if(xb < xa)
    swap(xa, xb);
  if(yb < ya)
    swap(ya, yb);
  vector<pair<int,int>> v;
  for(int i = xa; i <= xb; i++) {
    v.push_back({i, ya});
    v.push_back({i, yb});
  }
  for(int i = ya; i <= yb; i++){
    v.push_back({xa, i});
    v.push_back({xb, i});
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int x, y, r;
    cin >> x >> y >> r;
    for(int j = 0; j < v.size(); j++){
      if(dist(v[j].first, v[j].second, x, y) <= r * r)
        seen[j] = 1;
    }
  }
  int result = 0;
  for(int i = 0; i < v.size(); i++)
    result += 1 - seen[i];
  cout << result;
  return 0;
}