#include <iostream>
#include <array>
#include <vector>

using namespace std;

const int ALPH = 26;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

struct Bucket {
  array<int, ALPH> s;
  array<int, ALPH> t;
};

ll sum (const array<int, ALPH> &arr) {
  ll ans = 0;
  for (int i = 0; i < ALPH; i++) {
    ans += arr[i];
  }
  return ans;
}

ll dist (const Bucket &b) {
  ll tot = sum(b.s) * sum(b.t);
  for (int i = 0; i < ALPH; i++) {
    tot -= (ll) b.s[i] * (ll) b.t[i];
  }
  return tot;
}

int main () {
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  
  string s, t;
  cin >> s >> t;

  ll len = n * (ll) s.size();
  ll gc = gcd((ll) s.size(), (ll) t.size());
  ll lc = ((ll) s.size() * (ll) t.size()) / gc;

  vector<Bucket> buckets (gc);
  for (int i = 0; i < (int) s.size(); i++) {
    buckets[i % gc].s[s[i] - 'a']++;
  }

  for (int i = 0; i < (int) t.size(); i++) {
    buckets[i % gc].t[t[i] - 'a']++;
  }

  ll ans = 0;
  for (int i = 0; i < gc; i++) {
    ans += dist(buckets[i]);
  }

  ans *= (len / lc);
  cout << ans << endl;
}