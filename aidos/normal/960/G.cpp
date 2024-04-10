#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;

using namespace std;
int mod = 998244353;
int n, a, b;

ll F[200200];
ll binpow(ll x, ll k){
	ll res = 1;
	while(k > 0){
		if(k&1) res = res * x % mod;
		x = x*x % mod;
		k/=2;
	}
	return res;
}
ll C(int n, int k){
	if(n < k) return 0;
	if(k < 0) return 0;
	if(k > n) return 0;
	return F[n] * 1ll * binpow(F[k] * 1ll * F[n-k] % mod, mod-2) % mod;
}


#define ftype complex<double>

const double pi = acos(-1.);
int mask = (1 << 16) - 1, shift = 16;
const int maxn = 1 << 17;
ftype w[maxn];

template<typename T>
void fft(T *in, ftype *out, int n, int k = 1, bool inv = 0)
{
    if(n == 1)
    {
        *out = *in;
        return;
    }
    int t = maxn / n;
    n >>= 1;
    fft(in, out, n, 2 * k, inv);
    fft(in + k, out + n, n, 2 * k, inv);
    for(int i = 0, j = 0; i < n; i++, j += t)
    {
        ftype t = w[j] * out[i + n];
        out[i + n] = out[i] - t;
        out[i] += t;
        if(inv)
        {
            out[i] *= 0.5;
            out[i + n] *= 0.5;
        }
    }
}

vector<int> build(int l, int r)
{
    if(r - l == 1)
        return {l, 1};
    int m = (l + r) / 2;
    auto A = build(l, m);
    auto B = build(m, r);
    int n = A.size() + B.size() - 1;
    if(n < 500)
    {
        vector<int> C(n);
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < B.size(); j++)
            {
                C[i + j] += 1LL * A[i] * B[j] % mod;
                if(C[i + j] >= mod)
                    C[i + j] -= mod;
            }
        return C;
    }
    while(n & (n - 1)) n++;
    static ftype xy0[maxn], xy1[maxn];
    for(int i = 0; i < n; i++)
    {
        xy0[i] = (i < A.size() ? A[i] & mask : 0.) +
   ftype(0, 1) * (i < B.size() ? B[i] & mask : 0.);
        xy1[i] = (i < A.size() ? A[i] >> shift : 0.) +
   ftype(0, 1) * (i < B.size() ? B[i] >> shift : 0.);
    }
    static ftype XY0[maxn], XY1[maxn];
    fft(xy0, XY0, n);
    fft(xy1, XY1, n);
    static ftype X0[maxn], X1[maxn], Y0[maxn], Y1[maxn];
    for(int i = 0; i < n; i++)
    {
        X0[i] = (XY0[i] + conj(XY0[(n - i) % n])) / ftype(2, 0);
        X1[i] = (XY1[i] + conj(XY1[(n - i) % n])) / ftype(2, 0);
        Y0[i] = (XY0[i] - conj(XY0[(n - i) % n])) / ftype(0, 2);
        Y1[i] = (XY1[i] - conj(XY1[(n - i) % n])) / ftype(0, 2);
    }
    static ftype r0[maxn], r1[maxn], r2[maxn], R0[maxn], R1[maxn], R2[maxn];
    for(int i = 0; i < n; i++)
    {
        r0[i] = X0[i] * Y0[i];
        r1[i] = X0[i] * Y1[i] + X1[i] * Y0[i];
        r2[i] = X1[i] * Y1[i];
    }
    fft(r0, R0, n, 1, 1);
    fft(r1, R1, n, 1, 1);
    fft(r2, R2, n, 1, 1);
    reverse(R0 + 1, R0 + n);
    reverse(R1 + 1, R1 + n);
    reverse(R2 + 1, R2 + n);
    vector<int> ret(n);
    for(int i = 0; i < n; i++)
        ret[i] = (llround(R0[i].real())
              + ((llround(R1[i].real()) % mod) << shift)
              + ((llround(R2[i].real()) % mod) << 2 * shift)) % mod;
    while(ret.back() == 0)
        ret.pop_back();
    return ret;
}


void solve(){
	cin >> n >> a >> b;
	if(a + b>n+1){
		cout << 0 << endl;
		return;
	}
	if(a==0 || b == 0) {
		cout << 0 << endl;
		return;
	}
	if(a==1 && b==1){
		if(n==1){
			cout << 1 << endl;
		}else cout << 0 << endl;
		return;
	}
	F[0] = 1;
	for(int i = 0; i < maxn; i++)
        w[i] = {cos(2 * pi * i / maxn), sin(2 * pi * i / maxn)};
	
	for(int i = 1; i <= n; i++){
		F[i] = F[i-1] * i % mod;
	}
	vector<int> st = build(0, n-1);
	cout << C(a + b - 2, b-1) * 1ll * st[a+b-2]% mod;
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}