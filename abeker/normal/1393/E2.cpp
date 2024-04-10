#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 5;
const int MAXL = 1e6 + 5;
const int BASE = 3137;
const int MOD = 1e9 + 7;
 
int N;
int pot[MAXL];
int len[MAXN];
string s[MAXN];
vector <int> pref[MAXN];
vector <int> sorted[MAXN];
vector <int> dp[MAXN];
 
void load() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    s[i] = 'A' + s[i] + 'A';
  }
}
 
inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}
 
inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}
 
int range_hash(int x, int st, int l) {
  return add(pref[x][st + l - 1], -mul(pref[x][st - 1], pot[l]));
}

int removed_hash(int x, int rm, int l) {
  if (l < rm)
    return pref[x][l];
  return add(mul(pref[x][rm - 1], pot[l - rm + 1]), range_hash(x, rm + 1, l - rm + 1));
}
 
bool cmp(int x1, int rm1, int x2, int rm2) {
  int l1 = len[x1] - 2 - (rm1 < len[x1] - 1);
  int l2 = len[x2] - 2 - (rm2 < len[x2] - 1);
  int lo = 0, hi = min(l1, l2);
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (removed_hash(x1, rm1, mid) == removed_hash(x2, rm2, mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  lo++;
  if (lo == l2 + 1)
    return false;
  if (lo == l1 + 1)
    return true;
  return s[x1][lo + (lo >= rm1)] < s[x2][lo + (lo >= rm2)];
}
 
int solve() {
  pot[0] = 1;
  for (int i = 1; i < MAXL; i++)
    pot[i] = mul(pot[i - 1], BASE);
    
  for (int i = 0; i < N; i++) {
    len[i] = s[i].size();
    pref[i].resize(len[i]);
    for (int j = 1; j < len[i]; j++) {
      pref[i][j] = add(mul(pref[i][j - 1], BASE), s[i][j]);
      sorted[i].push_back(j);
    }
    vector <int> nxt(len[i]);
    nxt[len[i] - 1] = len[i] - 1;
    for (int j = len[i] - 2; j; j--)
      nxt[j] = s[i][j] != s[i][j + 1] ? j : nxt[j + 1];
    sort(sorted[i].begin(), sorted[i].end(), 
      [&](int x, int y) -> bool {
        bool swapped = false;
        if (x > y) {
          swapped = true;
          swap(x, y);
        }
        if (nxt[x] >= y)
          return false;
        if (swapped)
          return s[i][nxt[x]] < s[i][nxt[x] + 1];
        return s[i][nxt[x] + 1] < s[i][nxt[x]];
      }
    );
  }
  
  for (int i = 0; i < N; i++) {
    int ptr = -1, sum = 0;
    for (auto it : sorted[i]) 
      if (i) {
        while (ptr + 1 < sorted[i - 1].size() && !cmp(i, it, i - 1, sorted[i - 1][ptr + 1]))
          sum = add(sum, dp[i - 1][++ptr]);
        dp[i].push_back(sum);
      }
      else
        dp[i].push_back(1);
  }
 
  int sol = 0;
  for (auto it : dp[N - 1])
    sol = add(sol, it);
  
  return sol;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  load();
  cout << solve() << endl;
  return 0;
}