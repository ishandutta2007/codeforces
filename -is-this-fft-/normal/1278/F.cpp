#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long llong;

const int MOD = 998244353;
const int PRIMITIVE = 3;

struct modint {
  llong val;

  modint () {
    val = 0;
  }
  
  modint (llong _val) {
    val = _val % MOD;
  }
};

modint operator+ (modint p, modint q) {
  return modint(p.val + q.val);
}

modint operator- (modint p) {
  return modint(MOD - p.val);
}

modint operator- (modint p, modint q) {
  return p + (-q);
}

modint operator* (modint p, modint q) {
  return modint(p.val * q.val);
}

modint operator^ (modint p, int exponent) {
  if (exponent == 0) {
    return modint(1);
  } else {
    modint half = p^(exponent / 2);
    if (exponent % 2 == 1) {
      return half * half * p;
    } else {
      return half * half;
    }
  }
}

modint operator/ (modint p, modint q) {
  if (q.val == 0) {
    return modint(1/0);
  }
  return p * (q^(MOD - 2));
}

modint unity (int k) {
  /* primitive 2^k - th root of unity */
  return modint(PRIMITIVE)^(7 * 17 * (1 << (23 - k)));
}

modint prim_un [25];

ostream& operator<< (ostream &out, modint p) {
  out << p.val;
  return out;
}

int rev (int num, int bitc) {
  int ans = 0;
  for (int i = 0; i < bitc; i++) {
    ans *= 2;
    ans += num % 2;
    num /= 2;
  }
  return ans;
}    

vector<modint> ntt (vector<modint> a, int lengthlog) {
  vector<modint> A ((int) a.size());
  for (int i = 0; i < (int) A.size(); i++) {
    A[rev(i, lengthlog)] = a[i];
  }

  for (int s = 1; s <= lengthlog; s++) {
    modint twiddle = prim_un[s];
    int m = 1 << s;
    for (int k = 0; k < (int) a.size(); k += m) {
      modint omega (1);
      for (int j = 0; j < m / 2; j++) {
        modint t = omega * A[k + j + m / 2];
        modint u = A[k + j];
        A[k + j] = u + t;
        A[k + j + m / 2] = u - t;
        omega = omega * twiddle;
      }
    }
  }

  return A;
}

vector<modint> inv_ntt (vector<modint> a, int lengthlog) {
  int n = a.size();
  modint inv_n = modint(1) / modint(n);
  
  a = ntt(a, lengthlog);
  for (int i = 1; i < n / 2; i++) {
    swap(a[i], a[n - i]);
  }

  for (int i = 0; i < n; i++) {
    a[i] = a[i] * inv_n;
  }

  return a;
}

const int MAX_K = 1 << 14;

modint inv_fact [MAX_K];
modint fact [MAX_K];

vector<modint> multiply (vector<modint> p, vector<modint> q) {
  p = ntt(p, 14);
  q = ntt(q, 14);
  for (int i = 0; i < (int) p.size(); i++) {
    p[i] = p[i] * q[i];
  }
  p = inv_ntt(p, 14);

  for (int i = 5005; i < (int) p.size(); i++) {
    p[i] = modint(0);
  }
  return p;
}

vector<modint> fexp (vector<modint> p, int exponent) {
  if (exponent == 0) {
    vector<modint> ans ((int) p.size(), modint(0));
    ans[0] = modint(1);
    return ans;
  } else if (exponent == 1) {
    return p;
  } else if (exponent % 2 == 0) {
    vector<modint> half = fexp(p, exponent / 2);
    return multiply(half, half);
  } else if (exponent % 2 == 1) {
    vector<modint> shalf = fexp(p, exponent - 1);
    return multiply(shalf, p);
  }
}

int main () {
  for (int i = 0; i <= 23; i++) {
    prim_un[i] = unity(i);
  }
  
  fact[0] = modint(1);
  inv_fact[0] = modint(1);

  for (int i = 1; i < MAX_K; i++) {
    fact[i] = modint(i) * fact[i - 1];
    inv_fact[i] =( modint(1) / modint(i)) * inv_fact[i - 1];
  }
  
  int N, invp, K;
  cin >> N >> invp >> K;
  
  modint P = modint(1) / modint(invp);
  vector<modint> taylor (MAX_K, modint(0));
  for (int i = 0; i < 5005; i++) {
    taylor[i] = P * inv_fact[i];
  }
  taylor[0] = taylor[0] + (modint(1) - P);
  
  vector<modint> mgf = fexp(taylor, N);
  cout << mgf[K] * fact[K] << endl;
}