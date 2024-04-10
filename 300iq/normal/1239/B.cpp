#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 3e5 + 7;

pair <int, pair <int, int> > dp[N][3];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int bal = 0;
  for (auto c : s) {
    if (c == '(') bal++;
    else bal--;
  }
  if (bal != 0) {
    cout << 0 << '\n';
    cout << 1 << ' ' << 1 << '\n';
  } else {
    auto solve1 = [&] (string s) {
      vector <int> arr;
      int bal = 0;
      int mn = 0;
      for (auto c : s) {
        if (c == '(') bal++;
        else bal--;
        mn = min(mn, bal);
        arr.push_back(bal);
      }
      vector <int> cands = {mn - 2, mn - 1, mn};
      int n = (int) arr.size();
      pair <int, pair <int, int> > value = make_pair(0, make_pair(0, 0));
      for (int x : cands) {
        for (int i = 0; i <= (int) arr.size(); i++) {
          for (int t = 0; t < 3; t++) {
            int inf = -1e9;
            dp[i][t] = make_pair(inf, make_pair(0, 0));
          }
        }
        dp[0][0] = make_pair(0, make_pair(0, 0));
        for (int i = 0; i < (int) arr.size(); i++) {
          for (int t = 0; t < 3; t++) {
            if ((s[i] == '(' && !t) || t == 1) {
              int new_t = 1;
              int new_bal = arr[i] - 2;
              if (new_bal >= x) {
                auto me = dp[i][t];
                me.first += (new_bal == x);
                me.second.first = (t ? me.second.first : i);
                dp[i + 1][new_t] = max(dp[i + 1][new_t], me);
              }
            }
            if (t == 1 && s[i] == ')') {
              if (arr[i] >= x) {
                auto me = dp[i][t];
                me.first += (arr[i] == x);
                me.second.second = i;
                dp[i + 1][2] = max(dp[i + 1][2], me);
              }
            }
            if (t == 2 || t == 0) {
              if (arr[i] >= x) {
                auto me = dp[i][t];
                me.first += (arr[i] == x);
                dp[i + 1][t] = max(dp[i + 1][t], me);
              }
            }
          }
        }
        value = max(value, max(dp[n][0], dp[n][2]));
      }
      return value;
    };
    auto solve2 = [&] (string s) {
      vector <int> arr;
      int bal = 0;
      int mn = 0;
      for (auto c : s) {
        if (c == '(') bal++;
        else bal--;
        mn = min(mn, bal);
        arr.push_back(bal);
      }
      vector <int> cands = {mn, mn + 1, mn + 2};
      int n = (int) arr.size();
      pair <int, pair <int, int> > value = make_pair(0, make_pair(0, 0));
      for (int x : cands) {
        for (int i = 0; i <= (int) arr.size(); i++) {
          for (int t = 0; t < 3; t++) {
            int inf = -1e9;
            dp[i][t] = make_pair(inf, make_pair(0, 0));
          }
        }
        dp[0][0] = make_pair(0, make_pair(0, 0));
        for (int i = 0; i < (int) arr.size(); i++) {
          for (int t = 0; t < 3; t++) {
            if ((s[i] == ')' && !t) || t == 1) {
              int new_t = 1;
              int new_bal = arr[i] + 2;
              if (new_bal >= x) {
                auto me = dp[i][t];
                me.first += (new_bal == x);
                me.second.first = (t ? me.second.first : i);
                dp[i + 1][new_t] = max(dp[i + 1][new_t], me);
              }
            }
            if (t == 1 && s[i] == '(') {
              if (arr[i] >= x) {
                auto me = dp[i][t];
                me.first += (arr[i] == x);
                me.second.second = i;
                dp[i + 1][2] = max(dp[i + 1][2], me);
              }
            }
            if (t == 2 || t == 0) {
              if (arr[i] >= x) {
                auto me = dp[i][t];
                me.first += (arr[i] == x);
                dp[i + 1][t] = max(dp[i + 1][t], me);
              }
            }
          }
        }
        value = max(value, max(dp[n][0], dp[n][2]));
      }
      return value;
    };
    auto ret = solve1(s);
    auto go = solve2(s);
    ret = max(ret, go);
    cout << ret.first << '\n';
    cout << ret.second.first + 1 << ' ' << ret.second.second + 1 << '\n';
  }
}