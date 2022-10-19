#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 1e9 + 9;

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


int get_sum(int n, int a) {
  if (a == 1)
    return n;
  return mul(sub(bin(a, n), 1), inv(sub(a, 1)));
}
 
int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);
  //cerr << "mod = " << mod << endl;

  int n, k, a, b;

  cin >> n >> a >> b >> k;

  int ans = 0;
  int r = bin(mul(b, inv(a)), k);
  int sum = get_sum((n + 1) / k, r);

  for (int i = 0; i < k; ++i) {
    char c;
    cin >> c;
    int s = c == '+' ? 1 : mod - 1;

    int first = mul(bin(a, n - i), bin(b, i));

    //cerr << first << " " << get_sum((n + 1) / k, r) << endl;

    udd(ans, mul(s, first, sum));
  }

  cout << ans << endl;
}