#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using namespace std;

using ll = long long;
ll const inf = 6000000000000000000;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

set<int> myset[3];

ll dist(int x, int y){
  return 1LL * (x - y) * (x - y);
}

ll placemid(int x, set<int> &setleft, set<int> &setright){
  set<int>::iterator it = setleft.upper_bound(x);
  if(it == setleft.begin())
    return inf;
  it--;
  set<int>::iterator it2 = setright.lower_bound(x);
  if(it2 == setright.end())
    return inf;
  return dist(x, *it) + dist(x, *it2) + dist(*it, *it2);
}

void solve(){
  myset[1].clear();
  myset[2].clear();
  myset[3].clear();

  int n, m, k;
  cin >> n >> m >> k;
  ll result = inf;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    myset[1].insert(val);
  }
  for(int i = 1;i <= m; i++){
    int val;
    cin >> val;
    myset[2].insert(val);
  }
  for(int i = 1;i <= k; i++){
    int val;
    cin >> val;
    myset[3].insert(val);
  }
  for(set<int>::iterator it = myset[1].begin(); it != myset[1].end(); it++){
    result = min(result, placemid(*it, myset[2], myset[3]));
    result = min(result, placemid(*it, myset[3], myset[2]));
  }
  for(set<int>::iterator it = myset[2].begin(); it != myset[2].end(); it++){
    result = min(result, placemid(*it, myset[1], myset[3]));
    result = min(result, placemid(*it, myset[3], myset[1]));
  }
  for(set<int>::iterator it = myset[3].begin(); it != myset[3].end(); it++){
    result = min(result, placemid(*it, myset[1], myset[2]));
    result = min(result, placemid(*it, myset[2], myset[1]));
  }
  cout << result << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}
/*
1
2 2 2
1 2
5 4
6 7
*/