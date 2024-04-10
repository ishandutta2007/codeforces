#include <bits/stdc++.h>

#define ran(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;

using namespace std;

namespace FFT {
  const int mod = 1e9 + 7;
#ifndef M_PI
  const double M_PI = acos(-1.0);
#endif

  typedef complex<double> Comp;
  void fft_rec(Comp *arr, Comp *root_pow, int len) {
    if (len != 1) {
      fft_rec(arr,       root_pow, len >> 1);
      fft_rec(arr /*lp*/+ len/*rp*/, root_pow, len >> 1);
    }
    root_pow += len;
    ran(i, 0, len){
      tie(arr[i], arr[i + len]) = pair<Comp, Comp> {
        arr[i] /*lp*/+/*rp*/ root_pow[i] * arr[i + len],
        arr[i] /*lp*/-/*rp*/ root_pow[i] * arr[i + len] };
    }
  }
  void fft(vector<Comp> &arr, int ord, bool invert) {
    assert(arr.size() == 1 << ord);
    static vector<Comp> root_pow(1);
    static int inc_pow = 1;
    static bool is_inv = false;
    if (inc_pow <= ord) {
      int idx = root_pow.size();
      root_pow.resize(1 << ord);
      for (; inc_pow <= ord; ++inc_pow) {
        for (int idx_p = 0; idx_p < 1 << (ord - 1);
             idx_p += 1 << (ord - inc_pow), ++idx) {
          root_pow[idx] = Comp {
            cos(-idx_p * M_PI / (1 << (ord - 1))),
            sin(-idx_p * M_PI / (1 << (ord - 1))) };
          if (is_inv) root_pow[idx] = conj(root_pow[idx]);
        }
      }
    }
    if (invert != is_inv) {
      is_inv = invert;
      for (Comp &cur : root_pow) cur = conj(cur);
    }
    int j = 0;
    ran(i, 1, (1<<ord)){
      int m = 1 << (ord - 1);
      bool cont = true;
      while (cont) {
        cont = j & m;
        j ^= m;
        m >>= 1;
      }
      if (i < j) swap(arr[i], arr[j]);
    }
    fft_rec(arr.data(), root_pow.data(), 1 << (ord - 1));
    if (invert)
      ran(i, 0, 1<<ord) arr[i] /= (1 << ord);
  }

  void mult_poly_mod(vector<int> &a, vector<int> &b,
                     vector<int> &c) { // c += a*b
    static vector<Comp> arr[4];
    // correct upto 0.5-2M elements(mod ~= 1e9)
    if (c.size() < 400) {
      ran(i, 0, (int)a.size())
        ran(j, 0, min((int)b.size(), (int)c.size()-i))
        c[i + j] = ((ll)a[i] * b[j] + c[i + j]) % mod;
    } else {
      int ord = 32 - __builtin_clz((int)c.size()-1);
      if ((int)arr[0].size() != 1 << ord){
        ran(i, 0, 4) arr[i].resize(1 << ord);
      }
      ran(i, 0, 4)
        fill(arr[i].begin(), arr[i].end(), Comp{});
      for (int &cur : a) if (cur < 0) cur += mod;
      for (int &cur : b) if (cur < 0) cur += mod;
      const int shift = 15;
      const int mask = (1 << shift) - 1;
      ran(i, 0, (int)min(a.size(), c.size())){
        arr[0][i] += a[i] & mask;
        arr[1][i] += a[i] >> shift;
      }
      ran(i, 0, (int)min(b.size(), c.size())){
        arr[0][i] += Comp{0, (b[i] & mask)};
        arr[1][i] += Comp{0, (b[i] >> shift)};
      }
      ran(i, 0, 2) fft(arr[i], ord, false);
      ran(i, 0, 2){
        ran(j, 0, 2){
          int tar = 2 + (i + j) / 2;
          Comp mult = {0, -0.25};
          if (i ^ j) mult = {0.25, 0};
          ran(k, 0, 1<<ord){
            int rev_k = ((1 << ord) - k) % (1 << ord);
            Comp ca = arr[i][k] /*lp*/+/*rp*/ conj(arr[i][rev_k]);
            Comp cb = arr[j][k] /*lp*/-/*rp*/ conj(arr[j][rev_k]);
            arr[tar][k] = arr[tar][k] + mult * ca * cb;
          }
        }
      }
      ran(i, 2, 4){
        fft(arr[i], ord, true);
        ran(k, 0, (int)c.size()){
          c[k] = (c[k] + (((ll)(arr[i][k]/*lp*/.real()/*rp*/+0.5)%mod)
                          << (shift * (2 * (i-2) + /*lp*/0/*rp*/)))) % mod;
          c[k] = (c[k] + (((ll)(arr[i][k]/*lp*/.imag()/*rp*/+0.5)%mod)
                          << (shift * (2 * (i-2) + /*lp*/1/*rp*/)))) % mod;
        }
      }
    }
  }
}

const int MAX_N = 1 << 18;

int arr [MAX_N];

const int MAX_L = 5e5 + 5;

int can [MAX_L];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, X, Y;
  cin >> n >> X >> Y;

  vector<int> A (2 * MAX_N, 0);
  vector<int> B (2 * MAX_N, 0);
  for (int i = 0; i <= n; i++) {
    cin >> arr[i];
    A[arr[i]] = 1;
    B[MAX_N - arr[i]] = 1;
  }

  vector<int> C (2 * MAX_N, 0);
  FFT::mult_poly_mod(A, B, C);

  for (int i = MAX_N + 1; i < 2 * MAX_N; i++) {
    can[Y + i - MAX_N] = C[i] == 0 ? 0 : Y + i - MAX_N;
  }

  for (int i = 1; i < MAX_L; i++) {
    for (int j = i; j < MAX_L; j += i) {
      can[j] = max(can[j], can[i]);
    }
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int L;
    cin >> L;
    L /= 2;

    cout << (can[L] == 0 ? -1 : 2 * can[L]) << " ";
  }
  cout << endl;
}