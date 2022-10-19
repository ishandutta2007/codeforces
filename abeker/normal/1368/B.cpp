#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K;
string ans;

void solve(int len, int cnt) {
  ll tmp = 1;
  for (int i = 0; i < cnt && tmp < K; i++)
    tmp *= len;
  for (int i = 0; i < 10 - cnt && tmp < K; i++)
    tmp *= len + 1;
  if (tmp < K)
    return;
  string s = "";
  for (int i = 0; i < 10; i++)
    s += string(len + (i >= cnt), "codeforces"[i]);
  if (ans.empty() || s.size() < ans.size()) 
    ans = s;
}

int main() {
  scanf("%lld", &K);
  for (int i = 1; i < 50; i++)
    for (int j = 1; j <= 10; j++)
      solve(i, j);
  cout << ans << endl;
  return 0;
}