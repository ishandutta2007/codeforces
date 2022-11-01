#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, cnt[40];
bitset <40> vis;
string s[N];
string res;
vector <int> v[40];
string z[40];
vector <string> ans;

void merge (int at) {
  vis[at] = 1;
  if (res.empty()) {
    res = z[at];
    int changed = 1;
    while (changed) {
      changed = 0;
      for (char c : res) {
        if (!vis[c - 'a']) {
          merge(c - 'a');
          changed = 1;
          break;
        }
      }
    }
    return;
  }
  int res_at = -1, cur_at = -1;
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < z[at].size(); ++j) {
      if (res[i] == z[at][j]) {
        res_at = i, cur_at = j;
        break;
      }
    }
    if (res_at != -1) break;
  } 
  assert(res_at != -1);
  string forw = "", backw = "";
  for (int k = cur_at, j = res_at; k >= 0; --k, --j) {
    if (j < 0) {
      forw = z[at][k] + forw;
      continue;
    }
    if (z[at][k] != res[j]) {
      cout << "NO\n";
      exit(0);
    }
  }
  for (int k = cur_at, j = res_at; k < z[at].size(); ++k, ++j) {
    if (j >= res.size()) {
      backw += z[at][k];
      continue;
    }
    if (z[at][k] != res[j]) {
      cout << "NO\n";
      exit(0);
    }
  }
  res = forw + res + backw;
  int changed = 1;
  while (changed) {
    changed = 0;
    for (char c : res) {
      if (!vis[c - 'a']) {
        merge(c - 'a');
        changed = 1;
        break;
      }
    }
  }
  return;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    memset(cnt, 0, sizeof cnt);
    for (char c : s[i]) {
      ++cnt[c - 'a'];
      if (cnt[c - 'a'] > 1) {
        cout << "NO\n";
        return 0;
      }
      v[c - 'a'].push_back(i);
    }
  }

  for (int it = 0; it < 26; ++it) {
    z[it] = "";
    if (v[it].empty()) continue;
    string cur = "";
    for (int i : v[it]) {
      if (cur.empty()) {
        cur = s[i];
        continue;
      }
      int cur_at = 0, at = 0;
      while (cur_at < cur.size() and (cur[cur_at] - 'a') != it) ++cur_at;
      while (at < s[i].size() and (s[i][at] - 'a') != it) ++at;
      string forw = "", backw = "";
      for (int k = at, j = cur_at; k >= 0; --k, --j) {
        if (j < 0) {
          forw = s[i][k] + forw;
          continue;
        }
        if (s[i][k] != cur[j]) {
          cout << "NO\n";
          return 0;
        }
      }
      for (int k = at, j = cur_at; k < s[i].size(); ++k, ++j) {
        if (j >= cur.size()) {
          backw += s[i][k];
          continue;
        }
        if (s[i][k] != cur[j]) {
          cout << "NO\n";
          return 0;
        }
      }
      cur = forw + cur + backw;
    }
    z[it] = cur;
    // cout << cur << endl;
  }

  for (int i = 0; i < 26; ++i) {
    if (z[i].empty()) {
      vis[i] = 1;
    }
    if (vis[i]) continue;
    res = "";
    merge(i);
    // cout << res << endl;
    ans.push_back(res);
  }

  res = "";
  sort(ans.begin(), ans.end());
  for (string p : ans) res += p;

  memset(cnt, 0, sizeof cnt);
  for (char c : res) {
    ++cnt[c - 'a'];
    if (cnt[c - 'a'] > 1) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << res << '\n';
  return 0;
}