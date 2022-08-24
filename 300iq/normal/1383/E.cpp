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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  map <char, int> last;
  last['0'] = n;
  last['1'] = n;
  vector <int> j0(n), j1(n);
  for (int i = n - 1; i >= 0; i--) {
    last[s[i]] = i;
    j0[i] = last['0'];
    j1[i] = last['1'];
  }
  int i = 0;
  vector <int> ok;
  vector <int> ch;
  while (i < n) {
    ch.push_back(s[i] - '0');
    int j = i;
    int len = 0;
    while (j < n && s[i] == s[j]) {
      j++;
      len++;
    }
    i = j;
    ok.push_back(len);
  }
  vector <int> one((int) ok.size() + 1), zero((int) ok.size() + 1);
  one[0] = 1, zero[0] = 1;
  int m = (int) ok.size();
  int sum = 0;
  vector <int> push((int) ok.size());
  vector <int> append((int) ok.size());
  vector <int> first_more(ok.size());
  vector <int> st;
  for (int i = (int) ok.size() - 1; i >= 0; i--) {
    if (ch[i] == 0) {
      while (!st.empty() && ok[st.back()] <= ok[i]) {
        st.pop_back();
      }
      if (st.empty()) first_more[i] = m;
      else first_more[i] = st.back();
      st.push_back(i);
    }
  }
  if (ch[0] == 1) one[0] = 0;
  for (int i = 0; i < m; i++) {
    int mx = 0;
    if (ch.back() == 0 && (i == m - 1 || i != 0)) {
      add(zero[m], mul(one[i], ok.back()));
    }
    for (int j = i; j + 1 < m; j++) {
      if (ch[j] == 0) {
        if (i != 0) {
          add(append[j], mul(ok[j], one[i]));
          add(push[j], one[i]);
        }
        else {
          add(zero[j + 1], mul(ok[j], one[i]));
        }
        break;
      }
    }
    if (ch[i] == 0 && first_more[i] < m) {
      add(append[first_more[i]], mul(push[i], ok[first_more[i]] - ok[i]));
      add(push[first_more[i]], push[i]);
    }
    if (ch[i] == 0 && i + 1 < m) {
      add(zero[i + 1], append[i]);
    }
    add(sum, zero[i]);
    if (ch[i] == 1) {
      add(one[i + 1], mul(sum, ok[i]));
    }
  }
  int ans = zero[m];
  for (int i = 1; i <= m; i++) {
    add(ans, one[i]);
  }
  cout << ans << endl;
}