#include <iostream>

typedef long long llong;

const llong MAX_LG = 62;

using namespace std;

llong mod;

struct matrix {
  llong height, width;
  llong **val;
  
  matrix () {
  }

  matrix (llong _height, llong _width) {
    height = _height;
    width = _width;
    
    val = new llong* [height];
    for (llong i = 0; i < height; i++) {
      val[i] = new llong [width];
      for (llong j = 0; j < width; j++) {
        val[i][j] = 0;
      }
    }
  }

  void prllong () {
    for (llong i = 0; i < height; i++) {
      cout << "| ";
      for (llong j = 0; j < width; j++) {
        cout << val[i][j] << " ";
      }
      cout << "|\n";
    }
  }
};

matrix operator* (matrix p, matrix q) {
  matrix ans (p.height, q.width);

  for (llong i = 0; i < ans.height; i++) {
    for (llong j = 0; j < ans.width; j++) {
      for (llong k = 0; k < p.width; k++) {
        ans.val[i][j] += (p.val[i][k] * q.val[k][j]) % mod;
        ans.val[i][j] %= mod;
      }
    }
  }

  return ans;
}

matrix tpow [MAX_LG];
matrix fexp (matrix base, llong exponent) {
  tpow[0] = base;
  for (llong i = 1; i < MAX_LG; i++) {
    tpow[i] = tpow[i - 1] * tpow[i - 1];
  }

  matrix ans (2, 2);
  ans.val[0][0] = 1;
  ans.val[1][1] = 1;

  for (llong i = 0; i < MAX_LG; i++) {
    if (exponent & 1LL << i) {
      ans = ans * tpow[i];
    }
  }

  return ans;
}

llong lpow [MAX_LG];
llong lexp (llong base, llong exponent) {
  lpow[0] = base;
  for (llong i = 1; i < MAX_LG; i++) {
    lpow[i] = (lpow[i - 1] * lpow[i - 1]) % mod;
  }

  llong ans = 1;
  for (llong i = 0; i < MAX_LG; i++) {
    if (exponent & 1LL << i) {
      ans = ans * lpow[i];
      ans %= mod;
    }
  }

  return ans;
}

int main () {
  llong length, maxbit;
  llong exprk;

  cin >> length >> exprk >> maxbit >> mod;

  llong lebit = -1;
  for (llong i = 0; i < 64; i++) {
    if (exprk & 1ULL << i) {
      lebit = i;
    }
  }

  if (lebit >= maxbit) {
    cout << 0 << endl;
    return 0;
  }

  matrix fib (2, 2);
  fib.val[0][0] = 1;
  fib.val[0][1] = 1;
  fib.val[1][0] = 1;
  llong zeroans = fexp(fib, length + 1).val[0][0];
  llong oneans = ((lexp(2, length) - zeroans) % mod + mod) % mod;

  llong ans = 1;
  for (llong i = 0; i < maxbit; i++) {
    if (exprk & 1ULL << i) {
      ans *= oneans;
      ans %= mod;
    } else {
      ans *= zeroans;
      ans %= mod;
    }
  }

  cout << ans % mod << endl;
}