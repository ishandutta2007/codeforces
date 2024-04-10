#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

string solve_enough(string& s) {
  string sa, s_other;
  for (auto c: s) {
    if (c == s[0]) {
      sa += c;
    } else {
      s_other += c;
    }
  }
  reverse(s_other.begin(), s_other.end());
  sa.pop_back();
  sa.pop_back();
  string ans;
  ans += s[0];
  ans += s[0];
  while (!s_other.empty() || !sa.empty()) {
    assert(!s_other.empty());
    ans += s_other.back();
    s_other.pop_back();
    if (!sa.empty()) {
      ans += sa.back();
      sa.pop_back();
    }
  }
  return ans;
}

string solve_not_enough_2(string& s) {
  int cnt1 = 0, cnt2 = 0;
  for (auto c: s) {
    if (c == s[0]) cnt1++;
    if (c == s.back()) cnt2++;
  }
  assert(cnt1 + cnt2 == (int)s.size());
  cnt1--;
  string ans;
  ans += s[0];
  for (int i = 0; i < cnt2; ++i) {
    ans += s.back();
  }
  for (int i = 0; i < cnt1; ++i) {
    ans += s[0];
  }
  return ans;
}

string solve_not_enough_many(string& s) {
  map<char, int> m;
  for (auto c: s) {
    m[c]++;
  }
  vector<pair<char, int>> v{m.begin(), m.end()};
  assert(v.size() >= 3u);
  string ans;
  ans += v[0].first;
  v[0].second--;
  ans += v[1].first;
  v[1].second--;
  for (int i = 0; i < v[0].second; ++i) {
    ans += v[0].first;
  }
  v[0].second = 0;
  ans += v[2].first;
  v[2].second--;
  for (int i = 0; i < (int)v.size(); ++i) {
    for (int j = 0; j < v[i].second; ++j) {
      ans += v[i].first;
    }
  }
  assert(ans.size() == s.size());
  return ans;
}

string solve(string s) {
  int n = s.size();
  sort(s.begin(), s.end());
  if (s[0] == s[n - 1]) {
    return s;
  }
  int cnt_min = count(s.begin(), s.end(), s[0]);
  if (cnt_min == 1) {
    return s;
  }

  for (int i = 0; i < n; ++i) {
    bool has_same = false;
    if (i && s[i - 1] == s[i]) has_same = true;
    if (i + 1 < n && s[i + 1] == s[i]) has_same = true;
    if (!has_same) {
      string ans;
      ans += s[i];
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          ans += s[j];
        }
      }
      return ans;
    }
  }

  if (cnt_min <= n - cnt_min + 2) {
    return solve_enough(s);
  }

  set<int> cnt_diff;
  for (auto c: s) cnt_diff.insert(c);
  if (cnt_diff.size() == 2u) {
    return solve_not_enough_2(s);
  } else {
    return solve_not_enough_many(s);
  }
}

vector<int> prefix_function (string s) {
  int n = (int) s.length();
  vector<int> pi (n);
  for (int i=0; i<n; ++i)
    for (int k=0; k<=i; ++k)
      if (s.substr(0,k) == s.substr(i-k+1,k))
        pi[i] = k;
  return pi;
}

string solve_tl(string s) {
  sort(s.begin(), s.end());
  string ans = s;
  int val = 1e9;
  do {
     auto p = prefix_function(s);
     int cur = *max_element(p.begin(), p.end());
     if (cur < val) {
        val = cur;
        ans = s;
     }
  } while (next_permutation(s.begin(), s.end()));
  return ans;
}

void stress() {
  for (int i = 0; i < 10000; ++i) {
    int n = rand() % 4 + 2;
    string s;
    for (int i = 0; i < n; ++i) {
      int val = rand() % 6;
      s += (char)(val + 'a');
    }
    auto ans_my = solve(s);
    auto ans_tl= solve_tl(s);
    if (ans_my != ans_tl) {
      cout << "s: " << s << ", i: " << i << endl;
      cout << ans_my << endl << ans_tl << endl;
      assert(false);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
 // stress();
 // return 0;

  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
  }
}