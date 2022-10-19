#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// source: https://codeforces.com/contest/1562/submission/127229453
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool testing = 0;
const int N = 2e5+2;
int t[N];
ll a[N];
bool is_prime[N];
int queries;

ll query(int x, int y) {
  queries++;
  cout << "? " << x << " " << y << " " << endl;
  if (testing) {
    return (1LL * t[x] * t[y])/(__gcd(t[x], t[y]));
  }
  else {
    ll ans;
    cin >> ans;
    return ans;
  }
}

int myrandom(int n) {
  return rng()%n;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < N; i++) {
    is_prime[i] = 1;
  }
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) {
      for (int j = 2*i; j < N; j += i) {
        is_prime[j] = 0;
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (testing) {
      int l = rng()%(10000)+1;
      for (int i = 1; i <= n; i++) {
        t[i] = l+i-1;
      }
      random_shuffle(t+1, t+n+1, myrandom);
      for (int i = 1; i <= n; i++) {
        cout << t[i] << ' ';
      }
      cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
      a[i] = 0;
    }
    queries = 0;
    if ((1LL * n * (n-1))/2 <= n+5000) {
      for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
          ll val = query(i, j);
          a[i] = __gcd(val, a[i]);
          a[j] = __gcd(val, a[j]);
        }
      }
      if (n == 3 && a[1] % 2 == 0 && a[2] % 2 == 0 && a[3] % 2 == 0) {
        *max_element(a+1, a+n+1) /= 2;
      }
    }
    else {
      int key = 0;
      int p = 0;
      int trials = 250;
      while (trials--) {
        int x = rng()%n+1;
        a[x] = 0;
        int trials2 = 20;
        while (trials2--) {
          int y = x;
          while (y == x) y = rng()%n+1;
          a[x] = __gcd(a[x], query(x, y));
          if (a[x] < p) break;
        }
        if (is_prime[a[x]] && a[x] > p) {
          key = x;
          p = a[x];
        }
      }
      assert(key);
      for (int i = 1; i <= n; i++) {
        if (i == key) continue;
        a[i] = query(key, i)/p;
      }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
    if (testing) {
      for (int i = 1; i <= n; i++) assert(a[i] == t[i]);
      cout << queries << endl;
    }
  }
}