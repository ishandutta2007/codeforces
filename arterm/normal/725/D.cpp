#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 300300;

int n;
ll T;
pair<ll, ll> a[M];
int ptr = 0;
int cur = 0;
priority_queue<ll, vector<ll>, greater<ll>> q;

void read() {
  cin >> n;

  ll w;
  cin >> T >> w;

  --n;
  for (int i = 0; i < n; ++i) {
    ll t, w;
    cin >> t >> w;
    a[i] = make_pair(t, w);
  }
}

ll diff(int ptr) {
  return a[ptr].second - a[ptr].first + 1;
}

void go() {
  while (ptr < n && a[ptr].first > T) {
    q.push(diff(ptr));
    ++ptr;
    ++cur;
  }
}

void kill() {
  sort(a, a + n);
  reverse(a, a + n);


  int ans = 0;

  go();

  ans = cur;

  while (!q.empty() && T > 0) {
    ll mn = q.top();
    q.pop();
    if (mn > T)
      break;

    T -= mn;
    --cur;
    go();

    ans = min(ans, cur);
  }

  cout << ans + 1 << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}