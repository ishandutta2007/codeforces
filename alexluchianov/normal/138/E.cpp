#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
int const sigma = 26;
int v[1 + nmax], frec[1 + sigma], pos[1 + sigma][1 + 2 * nmax];
vector<pair<int,int>> constraint[1 + sigma];
int dp[1 + nmax];

bool satisfy(int x, int l, int r){
  return l <= x && x <= r;
}

int change(int x, int val, int l, int r){
  int result = -satisfy(dp[x], l, r) + satisfy(dp[x] + val, l, r);
  dp[x] += val;
  return result;
}

int updateinterval(int x, int y, int val, int l, int r){
  int result = 0;
  for(int i = x; i <= y; i++)
    result += change(i, val, l, r);
  return result;
}

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  for(int i = 1;i <= n; i++)
    v[i] = s[i - 1] - 'a' + 1;

  int q, l, r;
  cin >> q >> l >> r;
  int zerop = 0;

  for(int i = 1;i <= q; i++){
    char op;
    int x, y;
    cin >> op >> x >> y;
    constraint[op - 'a' + 1].push_back({x, y});
    if(x == 0)
      zerop++;
  }

  for(int i = 1;i <= sigma; i++)
    for(int j = 1; j <= 2 * nmax; j++)
      pos[i][j] = n + 1;

  for(int i = 1;i <= n; i++) {
    frec[v[i]]++;
    pos[v[i]][frec[v[i]]] = i;
  }

  ll result = 0, acc = 0;

  for(int i = n; 1 <= i; i--){
    dp[i] = zerop;
    if(satisfy(dp[i], l, r) == 1)
      acc++;
    for(int h = 0; h < constraint[v[i]].size(); h++){
      int x = constraint[v[i]][h].first;
      int y = constraint[v[i]][h].second;

      if(0 < x && pos[v[i]][frec[v[i]] + x - 1] != n + 1)
        acc += updateinterval(pos[v[i]][frec[v[i]] + x - 1], pos[v[i]][frec[v[i]] + x] - 1, 1, l, r);

      if(pos[v[i]][frec[v[i]] + y] != n + 1)
        acc += updateinterval(pos[v[i]][frec[v[i]] + y], pos[v[i]][frec[v[i]] + y + 1] - 1, -1, l, r);
    }
    frec[v[i]]--;
    result += acc;
  }
  cout << result;
  return 0;
}
/*
aaa
1 1 1
a 1 1
*/