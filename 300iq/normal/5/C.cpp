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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector <int> bal(n + 1);
  for (int i = 0; i < n; i++) {
    bal[i + 1] = bal[i];
    if (s[i] == '(') bal[i+1]++;
    else bal[i + 1]--;
  }
  vector <int> st;
  vector <int> ans(n + 1);
  int score = 1, ret = 0;
  for (int i = 0; i <= n; i++) {
    while (!st.empty() && bal[st.back()] > bal[i]) {
      st.pop_back();
    }
    if (!st.empty() && bal[st.back()] == bal[i]) {
      ans[i] = ans[st.back()];
      if (i - ans[i] > ret) {
        ret = i - ans[i];
        score = 1;
      } else if (i - ans[i] == ret) {
        score++;
      }
    } else {
      ans[i] = i;
    }
    st.push_back(i);
  }
  cout << ret << ' ' << score << '\n';
}