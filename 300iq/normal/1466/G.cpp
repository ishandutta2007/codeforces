#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

const int maxlen = 1e6;

vector <int> pi(string s) {
  int n = (int) s.size();
  vector <int> p(n);
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j && s[i] != s[j]) {
      j = p[j - 1];
    }
    j += (s[i] == s[j]);
    p[i] = j;
  }
  return p;
}

map <char, int> kek[50];

const int N = 1e5 + 20;

int pws[N];
map <char, int> fork[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  pws[0] = 1;
  for (int i = 1; i < N; i++) {
    pws[i] = mul(pws[i - 1], 2);
  }
  int n, q;
  cin >> n >> q;
  string s0, t;
  cin >> s0 >> t;
  map <char, int> coef;
  for (int i = 26; i <= n; i++) {
    for (auto &z : coef) {
      z.second = mul(z.second, 2);
    }
    add(coef[t[i - 1]], 1);
    fork[i] = coef;
  }
  string strs = s0;
  vector <ll> len(31);
  len[0] = (int) s0.size();
  for (int i = 1; i < 31; i++) {
    if ((int) strs.size() < maxlen) {
      strs = strs + t[i - 1] + strs;
    }
    len[i] = len[i - 1] * 2 + 1;
  }
  map <string, int> cnt;
  for (int i = 0; i < (int) s0.size(); i++) {
    string str = "";
    for (int j = i; j < (int) s0.size(); j++) {
      str += s0[j];
      cnt[str]++;
    }
  }
  while (q--) {
    for (int i = 0; i < 50; i++) kek[i].clear();
    int k;
    cin >> k;
    string w;
    cin >> w;
    vector <char> good_suf(w.size() + 1), good_pref(w.size() + 1);
    good_pref[0] = good_suf[0] = 1;
    map <char, int> good;
    {
      string orz = "";
      for (int i = 0; i < (int) w.size(); i++) {
        orz += strs[i];
      }
      orz += '$';
      orz += w;
      auto x = pi(orz);
      int me = x.back();
      while (me) {
        good_suf[me] = true;
        me = x[me - 1];
      }
    }
    {
      string orz = w;
      orz += '$';
      for (int i = max(0, (int) strs.size() - (int) w.size() - 1); i < (int) strs.size(); i++) {
        orz += strs[i];
      }
      auto x = pi(orz);
      int me = x.back();
      while (me) {
        good_pref[me] = true;
        me = x[me - 1];
      }
    }
    map <char, int> glob_cnt;
    for (int i = 0; i < (int) w.size(); i++) {
      int l = i, r = (int) w.size() - 1 - i;
      if (good_pref[l] && good_suf[r]) {
        int max_len = max(l, r);
        int j = 0;
        while (len[j] < max_len) j++;
        char me = w[i];
        kek[j][me]++;
        glob_cnt[me]++;
      }
    }
    for (int i = 1; i < 30; i++) {
      for (auto c : kek[i - 1]) {
        kek[i][c.first] += c.second;
      }
    }
    int ans = 0;
    if (w.size() <= s0.size()) ans = cnt[w];
    for (int i = 1; i <= min(k, 25); i++) {
      ans = mul(ans, 2);
      char seek = t[i - 1];
      add(ans, kek[i - 1][seek]);
    }
    if (k > 25) {
      ans = mul(ans, pws[k - 25]);
      for (auto c : glob_cnt) {
        add(ans, mul(c.second, fork[k][c.first]));
      }
    }
    cout << ans << '\n';
  }
}