#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int L[N], R[N], cnt[N];
bool dp[1<<N];

int char_to_index[256];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, a, b;
  string _s;
  cin >> n >> a >> b >> _s;
  vector<int> s(_s.begin(), _s.end());
  fill(char_to_index, char_to_index+256, -1);
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (char_to_index[s[i]] == -1) {
      char_to_index[s[i]] = k++;
    }
  }

  fill(L, L+k, n);

  for (int i = 0; i < n; i++) {
    int id = char_to_index[s[i]];
    R[id] = i;
    L[id] = min(L[id], i);
    cnt[id]++;
  }

  dp[0] = 1;
  for (int mask = 1; mask < (1<<k); mask++) {
    int l = n;
    int r = 0;
    int c = 0;
    for (int i = 0; i < k; i++) {
      if ((mask>>i)&1) {
        l = min(l, L[i]);
        r = max(r, R[i]);
        c += cnt[i];
      }
    }
    if (c*b >= (r-l+1)*a) {
      for (int i = 0; i < k; i++) {
        if (dp[mask&~(1<<i)]) {
          dp[mask] = 1;
          break;
        }
      }
    }
    for (int i = 1; i < k; i++) {
      int z = (1<<i)-1;
      if (dp[mask&z] && dp[mask&~z]) {
        dp[mask] = 1;
        break;
      }
    }
  }

  vector<char> ans;
  for (int c = 'a'; c <= 'z'; c++) {
    int id = char_to_index[c];
    if (id != -1 && dp[((1<<k)-1)^(1<<id)]) {
      ans.push_back(c);
    }
  }
  cout << ans.size();
  for (char c: ans) {
    cout << ' ' << c;
  }
  cout << '\n';
}