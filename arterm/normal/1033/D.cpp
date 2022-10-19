#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 505;
const ld N = 2e18 + 1e9;

const int mod = 998244353;

int add(int x) {  
  return x;
}

template<typename... T>
int add(int x, T... y) {  
  x += add(y...);
  if (x >= mod)
        x -= mod;
  return x;
}

template<typename... T>
int udd(int &x, T... y) { 
  return x = add(x, y...);
}

template<typename... T>
int sub(int x, T... y) { 
  return add(x, mod - add(y...));
}

int mul(int x) { 
  return x;
}

template<typename... T>
int mul(int x, T... y) { 
  return 1ll * x * mul(y...) % mod;
}

int bin(int x, int to) { 
  int y = 1;
  while (to) { 
        if (to & 1)
                  y = mul(x, y);
            x = mul(x, x);
                to >>= 1;
  }
  return y;
}

int inv(int x) { 
  assert(x != 0);
  return bin(x, mod - 2);
}
 

int n;
ll a[M];
map<ll, int> cnt;
map<ll, int> ung;

ll gcd(ll x, ll y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}

void crack(int k) {
  ll x = a[k];

  {
    ll y = sqrtl(sqrtl(x));

    for (ll i = max(0ll, y - 2); i <= y + 2; ++i) {
      ld j = i;
      if (j * j * j * j > N) break;
      if (x == i * i * i * i) {
        cnt[i] += 4;
        return;
      }
    }
  }
  
  {
    ll y = powl(x, 1. / 3);

    for (ll i = max(0ll, y - 2); i <= y + 2; ++i) {
      ld j = i;
      if (j * j * j  > N) break;
      if (x == i * i * i) {
        cnt[i] += 3;
        return;
      }
    }
  }

  {
    ll y = sqrtl(x);

    for (ll i = max(0ll, y - 2); i <= y + 2; ++i) {
      ld j = i;
      if (j * j > N) break;
      if (x == i * i) {
        cnt[i] += 2;
        return;
      }
    }
  }
  

  for (int j = 0; j < n; ++j) {
    ll y = gcd(a[k], a[j]);
    if (1 < y && y < a[k]) {
      assert(a[k] % y == 0);
      cnt[y]++;
      cnt[a[k] / y]++;
      return;
    }
  }

  ung[x]++;
}

void kill() {
  for (int i = 0; i < n; ++i) 
    crack(i);

  int ans = 1;
  for (auto e : cnt)
    ans = mul(ans, e.second + 1);

  for (auto e : ung)
    ans = mul(ans, bin(e.second + 1, 2));

  cout << ans << endl;
  cout.flush();
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}