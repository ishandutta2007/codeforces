#pragma GCC optimize ("Ofast") //10% performance
#include <complex.h>
#include <vector>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <iostream>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

namespace FFT {
  const int mod = 1e9 + 7;
#ifndef M_PI
  const double M_PI = acos(-1.0);
#endif
#define ran(i, a, b) for (auto i = (a); i < (b); i++)
  
  struct ModArithm {
    ull n;
    ld rec;
    ModArithm(ull _n) : n(_n) { // n in [2, 1<<63)
      rec = 1.0L / n;
    }
    // a, b in [0, min(2*n, 1<<63))
    ull multf(ull a, ull b) {
        ull mult = (ld)a * b * rec + 0.5L;
      ll res = a * b - mult * n;
      if (res < 0) res += n;
      return res; // in [0, n-1)
    }
    ull sqp1(ull a) { return multf(a, a) + 1; }
  };


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
    assert((int) arr.size() == 1 << ord);
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

  void mult_poly_mod (vector<int> &a, vector<int> &b,
                      vector<int> &c, int md = mod) { // c += a*b
    static vector<Comp> arr[4];
    // correct upto 0.5-2M elements(md ~= 1e9)
    // a and b are not modified except for sign correction
    if (c.size() < 400) {
      ran(i, 0, (int)a.size())
        ran(j, 0, min((int)b.size(), (int)c.size()-i))
        c[i + j] = ((ll)a[i] * b[j] + c[i + j]) % md;
    } else {
      int ord = 32 - __builtin_clz((int)c.size()-1);
      if ((int)arr[0].size() != 1 << ord){
        ran(i, 0, 4) arr[i].resize(1 << ord);
      }
      ran(i, 0, 4)
        fill(arr[i].begin(), arr[i].end(), Comp{});
      for (int &cur : a) if (cur < 0) cur += md;
      for (int &cur : b) if (cur < 0) cur += md;
      const int shift = 15;
      const int mask = (1 << shift) - 1;
      ran(i, 0, (int)min(a.size(), c.size())){
        arr[0][i] += a[i] & mask;
        arr[1][i] += a[i] >> shift;
      }
      ran(i, 0, (int)min(b.size(), c.size())){
        arr[0][i] += Comp{0, (double) (b[i] & mask)};
        arr[1][i] += Comp{0, (double) (b[i] >> shift)};
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
          c[k] = (c[k] + (((ll)(arr[i][k]/*lp*/.real()/*rp*/+0.5)%md)
                          << (shift * (2 * (i-2) + /*lp*/0/*rp*/)))) % md;
          c[k] = (c[k] + (((ll)(arr[i][k]/*lp*/.imag()/*rp*/+0.5)%md)
                          << (shift * (2 * (i-2) + /*lp*/1/*rp*/)))) % md;
        }
      }
    }
  }

  vector<ll> mult_poly_safe (vector<ll> &a, vector<ll> &b) {
    ll mods [2] = {1599999983, 1600000009};
    ll bigm = mods[0] * mods[1];
    ll bez [2] = {bigm - 553846157, 553846148};
    vector<int> as [2] = {vector<int> (0), vector<int> (0)};
    vector<int> bs [2] = {vector<int> (0), vector<int> (0)};
    vector<int> cs [2] = {vector<int> (a.size() + b.size(), 0),
                          vector<int> (a.size() + b.size(), 0)};
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < (int) a.size(); i++) {
        as[j].push_back(a[i] % mods[j]);
      }
      for (int i = 0; i < (int) b.size(); i++) {
        bs[j].push_back(b[i] % mods[j]);
      }
      mult_poly_mod(as[j], bs[j], cs[j], mods[j]);
    }

    vector<ll> c = vector<ll> (a.size() + b.size(), 0LL);
    auto ma = ModArithm(bigm);
    for (int i = 0; i < (int) c.size(); i++) {
      c[i] =
        (ma.multf(ma.multf(cs[0][i], bez[1]), mods[1]) +
         ma.multf(ma.multf(cs[1][i], bez[0]), mods[0])) % bigm;
    }
    return c;
  }
}

const int INF = 1e9 + 4;
const int MAX_N = 1 << 19;

vector<int> sim_pos (char c, const string &s, const string &t, int k) {
  vector<int> s_arr (s.size() + 2 * k, 0);
  int last = -INF;
  for (int i = 0; i < (int) s_arr.size(); i++) {
    if (i < (int) s.size() && s[i] == c) {
      last = i;
    }
    if (i - last <= 2 * k) {
      s_arr[i] = 1;
    }
  }

  vector<int> t_arr (t.size(), 0);
  int cnt = 0;
  for (int i = 0; i < (int) t_arr.size(); i++) {
    if (t[i] == c) {
      cnt++;
      t_arr[i] = 1;
    }
  }

  reverse(t_arr.begin(), t_arr.end());  
  vector<int> ans (s_arr.size() + t_arr.size(), 0);
  FFT::mult_poly_mod(s_arr, t_arr, ans);

  for (int i = 0; i < (int) ans.size(); i++) {
    if (ans[i] >= cnt) {
      ans[i] = 1;
    } else {
      ans[i] = 0;
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m, K;
  cin >> n >> m >> K;

  string s, t;
  cin >> s >> t;

  vector<int> ansA = sim_pos('A', s, t, K);
  vector<int> ansC = sim_pos('C', s, t, K);
  vector<int> ansG = sim_pos('G', s, t, K);
  vector<int> ansT = sim_pos('T', s, t, K);

  int ans = 0;
  for (int i = 0; i <= n - m; i++) {
    int p = i + K + m - 1;
    if (ansA[p] && ansC[p] && ansG[p] && ansT[p]) {
      ans++;
    }
  }
  cout << ans << endl;
}