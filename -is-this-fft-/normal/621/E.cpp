#include <iostream>
#include <iomanip>

typedef long long llong;

const int MOD = 1000000007;
const int MAX_MOD = 105;

using namespace std;

struct matrix {
  llong width, height, **val;

  matrix () {}

  matrix (llong _height, llong _width) {
    height = _height;    
    width = _width;

    val = new llong* [height];
    for (int i = 0; i < height; i++) {
      val[i] = new llong [width];
      for (int j = 0; j < width; j++) {
        val[i][j] = 0;
      }
    }
  }

  void print () {
    for (int i = 0; i < height; i++) {
      cout << "|";
      for (int j = 0; j < width; j++) {
        cout << setw(2) << val[i][j] << (j == width - 1 ? "|" : " ");
      }
      cout << endl;
    }
    cout << endl;
  }
};

matrix operator* (matrix p, matrix q) {
  matrix ans (p.height, q.width);

  for (int i = 0; i < p.height; i++) {
    for (int j = 0; j < q.width; j++) {
      for (int k = 0; k < p.width; k++) {
        ans.val[i][j] += (p.val[i][k] * q.val[k][j]) % MOD;
        ans.val[i][j] %= MOD;
      }
    }
  }

  return ans;
}

matrix tpow [62];
matrix fexp (matrix p, llong exp) {
  tpow[0] = p;
  for (int i = 1; i < 62; i++) {
    tpow[i] = tpow[i - 1] * tpow[i - 1];
  }
  
  matrix ans (p.height, p.height);
  for (int i = 0; i < p.height; i++) {
    ans.val[i][i] = 1;
  }

  for (int i = 0; i < 62; i++) {
    if (exp & 1LL << i) {
      ans = ans * tpow[i];
    }
  }
  return ans;
}


llong cnt [10];

int main () {
  llong digitc, blockc, trem, remc;
  cin >> digitc >> blockc >> trem >> remc;

  for (int i = 0; i < digitc; i++) {
    llong digit;
    cin >> digit;

    cnt[digit]++;
  }

  matrix mul (remc, remc);
  for (int i = 0; i < remc; i++) {
    for (int j = 0; j < 10; j++) {
      mul.val[(i * 10 + j) % remc][i] += cnt[j];
    }
  }

  matrix vals (remc, 1);
  for (int i = 0; i < 10; i++) {
    vals.val[i % remc][0] += cnt[i];
  }  

  cout << (fexp(mul, blockc - 1) * vals).val[trem][0] << endl;
}