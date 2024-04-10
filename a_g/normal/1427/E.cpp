#include <bits/stdc++.h>
using namespace std;

struct op {
  bool add;
  long long a;
  long long b;
};

vector<op> ops;

long long inversemod(long long p, long long q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  long long b = inversemod(q%p, p);
  long long a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long x;
  cin >> x;
  set<long long> nums;
  nums.insert(x);

  auto addop = [&] (long long a, long long b) {
    if (nums.count(a+b)) return;
    nums.insert(a+b);
    ops.push_back({1, a, b});
  };

  auto xop = [&] (long long a, long long b) {
    if (nums.count(a^b)) return;
    nums.insert(a^b);
    ops.push_back({0, a, b});
  };

  auto make_mult = [&] (long long k, long long m) {
    // starting with m, create k*m
    assert(k*m <= 3e18);
    for (long long i = 1; 2*i <= k; i *= 2) {
      addop(m*i, m*i);
    }
    long long s = 0;
    for (int i = 0; i < 50; i++) {
      if ((k>>i)&1) {
        addop(s, m<<i);
        s += (m<<i);
      }
    }
  };

  xop(x, x);
  make_mult(1<<__builtin_ctz(x-1), x);
  xop(x<<__builtin_ctz(x-1), x);

  long long u = 0, v = 0;
  bool win = 0;
  while (!win) {
    vector<long long> numvec(nums.begin(), nums.end());
    int m = numvec.size();
    for (int i = 0; i < m && !win; i++) {
      for (int j = i; j < m && !win; j++) {
        if (__gcd(numvec[i], numvec[j]) == 1) {
          u = numvec[i];
          v = numvec[j];
          win = 1;
          break;
        }
        xop(numvec[i], numvec[j]);
        if (numvec[i]+numvec[j] > 1e9) continue;
        addop(numvec[i], numvec[j]);
      }
    }
  }

  auto frob = [&] (long long t) {
    // make t as a linear combination of u and v
    long long a = ((t%v) * inversemod(u, v)) % v;
    long long b = (t-a*u)/v;
    assert(a >= 0 && b >= 0 && a*u + b*v == t);
    make_mult(a, u);
    make_mult(b, v);
    addop(a*u, b*v);
  };
  long long target = u*v;
  if (target&1) target++;
  frob(target);
  frob(target+1);
  xop(target, target+1);


  cout << ops.size() << '\n';
  for (op& o: ops) {
    cout << o.a << " " << (o.add ? "+" : "^") << " " << o.b << '\n';
  }
}