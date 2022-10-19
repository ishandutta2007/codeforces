#define _GLIBCXX_DEBUG
//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int p = 517;


const int MAXN = 10000 + 228;
int ppow[MAXN];
int hsh[MAXN];

void init_hashes(string s) {
  int n = s.size();
  ppow[0] = 1;
  for (int i = 0; i < n; i++) {
    ppow[i + 1] = 1LL * ppow[i] * p % MOD;
    hsh[i + 1] = (1LL * hsh[i] * p + s[i]) % MOD;
  }
}

int get_hash(int l, int r) {
  return ((hsh[r] - 1LL * hsh[l] * ppow[r - l]) % MOD + MOD) % MOD;
}

int get_hash(string s) {
  for (char &c : s) {
    c = tolower(c);
  }
  int h = 0;
  for (char c : s) {
    h = 1LL * h * p % MOD;
    h = (h + c) % MOD;
  }
  return h;
}

const int MAXM = 1e5 + 228;

string words[MAXM];
int hashes[MAXM];

int dp[MAXN];
int wi[MAXN];
int top = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  init_hashes(s);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> words[i];
  }
  for (int i = 0; i < m; i++) {
    hashes[i] = get_hash(words[i]);
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  dp[0] = m;
  unordered_map<int, int> rev;
  for (int i = 0; i < m; i++) {
    rev[hashes[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int len = 1; len <= 1000 && len <= i; len++) {
      int r = i;
      int l = i - len;
      int h = get_hash(l, r);
      if (dp[l] != -1) {
        if (rev.count(h) && (int) words[rev[h]].size() == len) {
          dp[r] = rev[h];
          break;
        }
      }
    }
  }
  int cur = n;
  assert(dp[n] != -1);
  while (cur != 0) {
    wi[top++] = dp[cur];
    cur -= words[dp[cur]].size();
  }
  for (int i = 0; i < top; i++) {
    cout << words[wi[i]] << " ";
  }
  cout << '\n';
}