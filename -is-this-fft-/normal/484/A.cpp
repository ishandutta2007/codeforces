#include <iostream>
#include <map>
#include <cassert>

using namespace std;

typedef long long ll;

const int MAX_LG = 60;

bool cmp (pair<int, ll> p, pair<int, ll> q) {
  if (p.first != q.first) {
    return p.first > q.first;
  }

  return p.second < q.second;
}

pair<int, ll> better (pair<int, ll> p, pair<int, ll> q) {
  if (cmp(p, q)) return p;
  return q;
}

map<pair<ll, ll>, pair<int, ll>> memo;

pair<int, ll> solve (ll, ll);

pair<int, ll> calc (ll L, ll R) {
  if (L == 0 && R == 0) {
    return make_pair(0, 0LL);
  }
  
  for (int k = MAX_LG; k >= 0; k--) {
    if ((L | R) & 1LL << k) {
      if (L & 1LL << k) {
        auto ans = solve(L - (1LL << k), R - (1LL << k));
        ans.first++;
        ans.second += 1LL << k;
        return ans;
      } else {
        auto la = solve(L, (1LL << k) - 1);
        auto ra = solve(0, R - (1LL << k));
        ra.first++;
        ra.second += 1LL << k;
        return better(la, ra);
      }
    }
  }

  assert(false);
}

pair<int, ll> solve (ll L, ll R) {
  if (memo.count(make_pair(L, R))) {
    return memo[make_pair(L, R)];
  }

  auto ans = calc(L, R);
  memo[make_pair(L, R)] = ans;
  return ans;
}

void solve () {
  ll L, R;
  cin >> L >> R;

  cout << solve(L, R).second << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}