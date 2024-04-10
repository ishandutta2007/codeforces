#include <iostream>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_LG = 15;
const int MAX_A = 1 << MAX_LG;
const int ITERS = 100;

mt19937 rng;

string sol;
int n, m;
string arr [MAX_N];

vector<int> setpos (const string &s) {
  vector<int> ans;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '1') {
      ans.push_back(i);
    }
  }
  return ans;
}

int cntpos (const string &s) {
  int ans = 0;
  for (char c : s) {
    if (c == '1') {
      ans++;
    }
  }
  return ans;
}

int apply (const string row, const vector<int> &bits) {
  int ans = 0;
  for (int i = 0; i < (int) bits.size(); i++) {
    if (row[bits[i]] == '1') {
      ans |= 1 << i;
    }
  }
  return ans;
}

int cnt [MAX_A];

void solve () {
  int spec = rng() % n;
  auto bits = setpos(arr[spec]);

  for (int i = 0; i < MAX_A; i++) {
    cnt[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    cnt[apply(arr[i], bits)]++;
  }

  for (int k = 0; k < MAX_LG; k++) {
    for (int i = MAX_A - 1; i >= 0; i--) {
      if (!(i & 1 << k)) {
        cnt[i] += cnt[i | 1 << k];
      }
    }
  }

  int best = 0;
  for (int i = 0; i < MAX_A; i++) {
    if (cnt[i] >= (n + 1) / 2 && __builtin_popcount(i) > __builtin_popcount(best)) {
      best = i;
    }
  }

  if (__builtin_popcount(best) > cntpos(sol)) {
    sol = string(m, '0');
    for (int i = 0; i < (int) bits.size(); i++) {
      if (best & 1 << i) {
        sol[bits[i]] = '1';
      }
    }
  }
}

int main () {
  rng = mt19937 (chrono::steady_clock::now().time_since_epoch().count());
  
  ios::sync_with_stdio(false);

  int P;
  cin >> n >> m >> P;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sol = string(m, '0');
  for (int i = 0; i < ITERS; i++) {
    solve();
  }

  cout << sol << '\n';
}