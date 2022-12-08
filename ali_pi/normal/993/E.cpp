#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;
typedef complex<double> base;

vector<base> fa, fb;
int a[N], n, x;
int c[N], f[N];
long long ans[N];

const long double PI = acos(-1);

void fft (vector<base> &a, bool invert) {
 int n = (int) a.size();
 for (int i = 1, j = 0; i < n; ++i) {
  int bit = (n >> 1);
  for (;j >= bit; bit >>= 1) j -= bit;
  j += bit;
  if (i < j) swap (a[i], a[j]);
 }
 for (int len = 2; len <= n; len <<= 1) {
  double ang = 2 * PI / len * (invert ? -1 : 1);
  base wlen (cos(ang), sin(ang));
  for (int i = 0; i < n; i += len) {
   base w (1);
   for (int j = 0; j < len / 2; ++j) {
    base u = a[i + j],  v = a[i + j + len / 2] * w;
    a[i + j] = u + v;
    a[i + j + len/2] = u - v;
    w *= wlen;
   }
  }
 }
 if (invert)
  for (int i=0; i<n; ++i)
       a[i] /= n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1];
        if (a[i] < x) f[i]++;
    }
    for (int i = 0; i <= n; i++)
         c[f[i]]++;
    fa.resize((1 << 19));
    fb.resize((1 << 19));
    for (int i = 0; i <= n; i++)  
         fa[i] = c[i];
    for (int i = 0; i <= n; i++) 
         fb[i] = c[n - i];
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < fa.size(); i++) 
         fa[i] *= fb[i];
    fft(fa, true);
    for (int i = n; i <= n + n; i++)
         ans[i - n] = (long long)(fa[i].real() + 0.5);
    ans[0] = (ans[0] - n) / 2;
    for (int i = 0; i <= n; i++) 
         cout << ans[i] << " ";
    cout << "\n";
}