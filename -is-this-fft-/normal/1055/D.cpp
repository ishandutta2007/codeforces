#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 1e15 + 37;
int base;

pair<int, int> diff (string s, string t) {
  int first_idx = -1, last_idx = -1;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != t[i]) {
      if (first_idx == -1) {
        first_idx = i;
      }
      last_idx = i;
    }
  }

  return make_pair(first_idx, last_idx);
}

ll hsh (string s) {
  ll ans = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    ans *= base;
    ans += s[i];
    ans %= mod;
  }
  return ans;
}

int first_occ (string text, ll pat, ll pat_exp, int patl) {
  ll thash = 0;
  for (int i = 0; i < (int) text.size(); i++) {
    thash *= base;
    thash += text[i];
    thash %= mod;

    if (i >= patl) {
      thash -= (pat_exp * text[i - patl]) % mod;
      thash += mod;
      thash %= mod;
    }

    if (i >= patl - 1) {
      if (thash == pat) {
        return i - patl + 1;
      }
    }
  }
  return -1;
}

const int maxn = 3005;

string src [maxn], target [maxn];
pair<int, int> change [maxn];
  
int main () {
  ios::sync_with_stdio(false);
  
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  base = 129 + rand() % 300;

  int varc;
  cin >> varc;
  for (int i = 0; i < varc; i++) {
    cin >> src[i];
  }
  for (int i = 0; i < varc; i++) {
    cin >> target[i];
  }

  int diffidx = -1;
  for (int i = 0; i < varc; i++) {
    if (src[i] != target[i]) {
      diffidx = i;
    }
  }
  change[diffidx] = diff(src[diffidx], target[diffidx]);

  vector<int> diffs;
  for (int i = 0; i < varc; i++) {
    if (src[i] != target[i]) {
      diffs.push_back(i);
      change[i] = diff(src[i], target[i]);

      if (src[i].substr(change[i].first, change[i].second - change[i].first + 1) !=
          src[diffidx].substr(change[diffidx].first, change[diffidx].second - change[diffidx].first + 1)) {
        cout << "NO" << endl;
        return 0;
      }

      if (target[i].substr(change[i].first, change[i].second - change[i].first + 1) !=
          target[diffidx].substr(change[diffidx].first, change[diffidx].second - change[diffidx].first + 1)) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }


  while (true) {
    if (change[diffs[0]].first == 0) break;
    bool ok = true;
    for (int k : diffs) {
      if (change[k].first == 0) ok = false;
      if (src[k][change[k].first - 1] != src[diffs[0]][change[diffs[0]].first - 1]) ok = false;
      if (target[k][change[k].first - 1] != target[diffs[0]][change[diffs[0]].first - 1]) ok = 0;
    }

    if (!ok) break;
    for (int k : diffs) {
      change[k].first--;
    }
  }

  while (true) {
    if (change[diffs[0]].second == (int) src[diffs[0]].size() - 1) break;
    bool ok = true;
    for (int k : diffs) {
      if (change[k].second == (int) src[k].size() + 1) ok = false;
      if (src[k][change[k].second + 1] != src[diffs[0]][change[diffs[0]].second + 1]) ok = false;
      if (target[k][change[k].second + 1] != target[diffs[0]][change[diffs[0]].second + 1]) ok = 0;
    }

    if (!ok) break;
    for (int k : diffs) {
      change[k].second++;
    }
  }

  pair<string, string> transf = make_pair(src[diffidx].substr(change[diffidx].first, change[diffidx].second - change[diffidx].first + 1), target[diffidx].substr(change[diffidx].first, change[diffidx].second - change[diffidx].first + 1));
  ll pat = hsh(transf.first);
  ll pat_exp = 1;
  for (int i = 0; i < (int) transf.first.size(); i++) {
    pat_exp *= base;
    pat_exp %= mod;
  }

  for (int i = 0; i < varc; i++) {
    int idx = first_occ(src[i], pat, pat_exp, transf.first.size());
    if (idx != -1) {
      for (int j = 0; j < (int) transf.second.size(); j++) {
        src[i][j + idx] = transf.second[j];
      }
    }
  }

  for (int i = 0; i < varc; i++) {
    if (src[i] != target[i]) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << endl;
  cout << transf.first << endl;
  cout << transf.second << endl;
}