#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

template<typename T, typename U>
ostream& operator<< (ostream &out, pair<T, U> pr) {
  out << pr.first << " " << pr.second;
  return out;
}

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

struct frac {
  ll p, q;

  frac () : p(0), q(1) {}

  frac (ll _p) : p(_p), q(1) {}

  frac (ll _p, ll _q) {
    ll gc = gcd(_p, _q);
    p = _p / gc;
    q = _q / gc;

    if (q < 0) {
      q *= -1;
      p *= -1;
    }
  }
};

frac operator+ (frac x, frac y) {
  return frac(x.p * y.q + x.q * y.p, x.q * y.q);
}

frac operator- (frac x) {
  return frac(-x.p, x.q);
}

frac operator- (frac x, frac y) {
  return x + (-y);
}

frac operator* (frac x, frac y) {
  return frac(x.p * y.p, x.q * y.q);
}

frac operator/ (frac x, frac y) {
  return frac(x.p * y.q, x.q * y.p);
}

bool operator== (frac x, frac y) {
  return x.p * y.q == x.q * y.p;
}

bool operator< (frac x, frac y) {
  return x.p * y.q < x.q * y.p;
}

bool operator<= (frac x, frac y) {
  return x < y || x == y;
}

bool operator> (frac x, frac y) {
  return x.p * y.q > x.q * y.p;
}

bool operator>= (frac x, frac y) {
  return x > y || x == y;
}

bool operator!= (frac x, frac y) {
  return !(x == y);
}

ostream& operator<< (ostream &out, frac x) {
  out << x.p << '/' << x.q;
  return out;
}

ll floor (frac x) {
  return x.p / x.q;
}

ll ceil (frac x) {
  return (x.p + x.q - 1) / x.q;
}

ll ll_sqrt (ll x) {
  for (ll i = 0; i * i <= x; i++) {
    if (i * i == x) {
      return i;
    }
  }
  return 0;
}

const ll MAX_N = 1e3 + 5;

ll x [MAX_N], y [MAX_N];

pair<ll, ll> slope (ll a, ll b) {
  if (x[a] > x[b]) {
    swap(a, b);
  }
  ll dx = x[b] - x[a];
  ll dy = y[b] - y[a];
  ll gc = gcd(abs(dx), abs(dy));
  dx /= gc;
  dy /= gc;
  if (dx == 0 && dy < 0) dy = -dy;
  return {dx, dy};
}

frac defp (ll a, ll b) {
  pair<ll, ll> s = slope(a, b);
  if (s.first == 0) return frac(x[a]);
  if (s.second == 0) return frac(y[a]);
  if (x[a] > x[b]) {
    swap(a, b);
  }
  return frac(x[a]) - frac(y[a]) * frac(s.first, s.second);
}

int main () {
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  vector<pair<pair<ll, ll>, frac>> lines;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      lines.push_back({slope(i, j), defp(i, j)});
    }
  }

  sort(lines.begin(), lines.end());
  vector<pair<ll, ll>> rlines;
  for (ll i = 0; i < (ll) lines.size(); i++) {
    // cout << lines[i].first.first << " " << lines[i].first.second << " " << lines[i].second << endl;
    if (i == 0 || lines[i] != lines[i - 1]) {
      rlines.push_back(lines[i].first);
    }
  }

  ll rlc = rlines.size();
  ll ans = rlc * (rlc - 1) / 2;
  vector<ll> blocks;
  for (ll i = 0; i < (ll) rlines.size(); i++) {
    if (i == 0 || rlines[i] != rlines[i - 1]) {
      blocks.push_back(0);
    }
    blocks.back()++;
  }

  for (ll u : blocks) {
    ans -= u * (u - 1) / 2;
  }

  cout << ans << endl;
}