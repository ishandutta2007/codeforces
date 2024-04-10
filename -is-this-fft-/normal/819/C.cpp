#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_P = 2e6 + 5;

ll factor [MAX_P];

// factors of pqr
vector<pair<ll, ll>> factorize (ll p, ll q, ll r) {
  vector<ll> fs;
  while (p != 1) {
    fs.push_back(factor[p]);
    p /= factor[p];
  }
  while (q != 1) {
    fs.push_back(factor[q]);
    q /= factor[q];
  }
  while (r != 1) {
    fs.push_back(factor[r]);
    r /= factor[r];
  }

  sort(fs.begin(), fs.end());
  vector<pair<ll, ll>> ans;
  for (ll i = 0; i < (ll) fs.size(); i++) {
    if (i == 0 || fs[i] != fs[i - 1]) {
      ans.push_back(make_pair(fs[i], 0));
    }
    ans.back().second++;
  }

  return ans;
}

// # of multiples of p in 1...m
ll cnt_muls (ll p, ll m) {
  return m / p;
}

ll sgn (ll mask) {
  return (__builtin_popcount(mask) % 2) ? -1 : 1;
}

ll sub_mul (ll mask, const vector<ll> &vals) {
  ll ans = 1;
  for (ll i = 0; i < (ll) vals.size(); i++) {
    if (mask & 1 << i) {
      ans *= vals[i];
    }
  }
  return ans;
}

ll solve_a (const vector<pair<ll, ll>> &n_fs,
            const vector<pair<ll, ll>> &S_fs, ll m) {

  /*
  cout << "==========================================" << endl;
  for (auto pr : n_fs) {
    cout << "(" << pr.first << " " << pr.second << ") ";
  }
  cout << endl;

  for (auto pr : S_fs) {
    cout << "(" << pr.first << " " << pr.second << ") ";
  }
  cout << endl;
  */
  
  // factors of n that are not factors of 2S
  vector<pair<ll, ll>> forbs;
  ll iptr = 0, jptr = 0;
  while (iptr < (ll) n_fs.size()) {
    while (jptr < (ll) S_fs.size() && S_fs[jptr].first < n_fs[iptr].first) {
      jptr++;
    }

    if (jptr < (ll) S_fs.size() && S_fs[jptr].first == n_fs[iptr].first) {
      if (n_fs[iptr].second > S_fs[jptr].second) {
        forbs.push_back(S_fs[jptr]);
        forbs.back().second++;
      }
    } else {
      forbs.push_back(make_pair(n_fs[iptr].first, 1));
    }
    iptr++;
  }

  /*
  for (auto pr : forbs) {
    cout << "(" << pr.first << " " << pr.second << ") ";
  }
  cout << endl;
  */

  vector<ll> forb_vals;
  for (auto pr : forbs) {
    ll pw = 1;
    for (ll i = 0; i < pr.second; i++) {
      pw *= pr.first;
    }
    forb_vals.push_back(pw);
  }

  /*
  for (auto f : forb_vals) {
    cout << f << " ";
  }
  cout << endl;
  */

  ll ans = 0;
  for (ll mask = 0; mask < 1 << (ll) forb_vals.size(); mask++) {
    ans += sgn(mask) * cnt_muls(sub_mul(mask, forb_vals), m);
  }
  return ans;
}

void solve_b_dfs (ll cur, ll id, const vector<pair<ll, ll>> &S_fs, ll n, ll &ans) {
  if (cur > n) {
    return;
  }
  
  if (id == (ll) S_fs.size()) {
    ans++;
    return;
  }

  if (id < (ll) S_fs.size()) {
    for (ll i = 0; i <= S_fs[id].second; i++) {
      solve_b_dfs(cur, id + 1, S_fs, n, ans);
      cur *= S_fs[id].first;
    }
  }
}

ll solve_b (const vector<pair<ll, ll>> &S_fs, ll n) {
  ll ans = 0;
  solve_b_dfs(1, 0, S_fs, n, ans);
  return ans;
}

void solve () {
  ll n1, n2, n3;
  cin >> n1 >> n2 >> n3;

  ll m1, m2, m3;
  cin >> m1 >> m2 >> m3;

  ll s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  s1 *= 2;

  auto n_fs = factorize(n1, n2, n3);
  auto m_fs = factorize(m1, m2, m3);
  auto s_fs = factorize(s1, s2, s3);
  
  cout << solve_a(n_fs, s_fs, m1 * m2 * m3) + solve_b(s_fs, n1 * n2 * n3) << endl;
}

int main () {
  for (ll i = 2; i < MAX_P; i++) {
    if (!factor[i]) {
      for (ll j = i; j < MAX_P; j += i) {
        factor[j] = i;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  
  ll testc;
  cin >> testc;

  for (ll i = 0; i < testc; i++) {
    solve();
  }
}