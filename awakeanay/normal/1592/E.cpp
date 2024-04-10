#include <iostream>
#include <vector>
#include <queue>

const int LOG = 20;
const int MAXN = 1000006;

// first[j][i] is largest k such that all numbers from k to i
// have jth bit set
int first[LOG][MAXN];
int n;
int a[MAXN];
int pref[MAXN];

int best = 0;

void solve(const std::vector<int> &s, int b) {
  if(b == -1 || s.empty())
    return;

  std::queue<int> par[2];
  for(int j : s) {
    int m = j%2;
    par[m].push(j);
    while(par[m].front()+1 < first[b][j])
      par[m].pop();
    best = std::max(best, j-par[m].front());
  }

  std::vector<int> ns[2];
  for(int j : s) {
    int cur = (pref[j] >> b)&1;
    ns[cur].push_back(j);
  }

  solve(ns[0], b-1);
  solve(ns[1], b-1);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;

  for(int i = 0; i < n; i++) {
    std::cin >> a[i+1];
  }

  for(int i = 0; i < LOG; i++) {
    first[i][0] = 1;
    for(int j = 1; j <= n; j++) {
      if((a[j] >> i)&1)
        first[i][j] = first[i][j-1];
      else
        first[i][j] = j+1;
    }
  }

  int andp = a[1];
  int xorp = 0;
  pref[0] = 0;
  for(int i = 1; i <= n; i++) {
    pref[i] = pref[i-1]^a[i];
    xorp ^= a[i];
    andp &= a[i];
    if(andp > xorp)
      best = i;
  }

  std::vector<int> s;
  for(int i = 0; i < n; i++)
    s.push_back(i+1);
  solve(s, LOG-1);

  std::cout << best << std::endl;

  return 0;
}