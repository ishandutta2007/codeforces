#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

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

const int M = 200200;

int n, k;
int a[M], b[M];
int pos[M];
int tim[M];
set<pair<int, int>> rem;

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    pos[a[i]] = i;
  }

  fill(tim, tim + n, -1);

  for (int i = 0; i < k; ++i) {
    cin >> b[i];
    --b[i];
    tim[b[i]] = i;
  }
}

void kill() {
  int ans = 1;
  rem.clear();
  for (int i = 0; i < n; ++i)
    rem.emplace(i, a[i]);

  for (int i = 0; i < k; ++i) {
    int x = b[i];
    int at = pos[x];
    auto it = rem.find(make_pair(at, x));
    assert(it != rem.end());

    int cnt = 0;

    if (it != rem.begin() && tim[prev(it)->second] <= i)
      ++cnt;
    if (next(it) != rem.end() && tim[next(it)->second] <= i)
      ++cnt;

    ans = mul(ans, cnt);
    if (cnt == 0)
      break;

    rem.erase(it);
  }

  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    read();
    kill();
  }

}