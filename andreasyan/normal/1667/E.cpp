#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

template<const int md>
struct ntt{
	inline void add(int &a, int b) { a += b; if(a >= md) a -= md; }
	inline void sub(int &a, int b) { a -= b; if(a < 0) a += md; }
	inline int add2(int a, int b) { a += b; if(a >= md) a -= md; return a;}
	inline int sub2(int a, int b) { a -= b; if(a < 0) a += md; return a;}
	inline int mul(int a, int b) { return (int)((ll)a*b%md); }
	inline int power(int a, long long b) {
		int res = 1;
		while (b > 0) {
			if (b & 1) res = mul(res, a);
	    	a = mul(a, a);
			b >>= 1;
		}
		return res;
	}
	inline int inv(int a) {
		a %= md;
		if (a < 0) a += md;
		int b = md, u = 0, v = 1;
		while (a) {
			int t = b / a;
			b -= t * a; swap(a, b);
			u -= t * v; swap(u, v);
		}
		assert(b == 1);
		if (u < 0) u += md;
		return u;
	}

 	int max_base, root;
	vector<int> dw, idw;
	ntt() {
		int tmp = md - 1;
		max_base = 0;
		while (tmp % 2 == 0) {
			tmp /= 2;
			max_base++;
		}
		root = 2;
		while (power(root, (md-1)>>1) == 1) root++;
		dw.resize(max_base); idw.resize(max_base);
		for (int i = 0; i < max_base; ++i){
			sub(dw[i], power(root, (md-1) >> (i+2)));
			idw[i] = inv(dw[i]);
		}
	}
	void fft(vector<int> &a, bool inv) {
		const int n = a.size();
		assert((n & (n - 1)) == 0);
		assert(__builtin_ctz(n) <= max_base);
		if(!inv){
			for(int m=n;m>>=1;){
				int w = 1;
				for(int s=0,k=0; s<n; s += 2*m){
					for(int i=s, j=s+m ; i < s+m; ++i, ++j) {
						int x = a[i], y = mul(a[j], w);
						a[j] = (x>=y?x-y:x+md-y);
						a[i] = (x+y>=md?x+y-md:x+y);
					}
					w = mul(w, dw[__builtin_ctz(++k)]);
				}
			}
		}
		else{
			for(int m=1;m<n;m*=2){
				int w = 1;
				for(int s=0,k=0; s<n; s += 2*m){
					for(int i=s, j=s+m ; i < s+m; ++i, ++j) {
						int x = a[i], y = a[j];
						a[j] = (x>=y?x-y:x+md-y);
						a[j] = mul(a[j], w);
						a[i] = (x+y>=md?x+y-md:x+y);
					}
					w = mul(w, idw[__builtin_ctz(++k)]);
				}
			}
		}
	}
	vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
		int need = a.size() + b.size() - 1;
		int nbase = 0;
		while ((1 << nbase) < need) nbase++;
		int sz = 1 << nbase;
		a.resize(sz);
		b.resize(sz);
		fft(a, 0);
		if (eq) b = a; else fft(b, 0);
		int inv_sz = inv(sz);
		for (int i = 0; i < sz; i++) {
			a[i] = mul(mul(a[i], b[i]), inv_sz);
		}
		fft(a, 1);
		a.resize(need);
		return a;
	}
	vector<int> square(vector<int> a) {
		return multiply(a, a, 1);
	}
};

const int N = 200005, M = 998244353;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int f[N], rf[N];
int pr[N];

int n;
int u[N];

int ans[N];

void solv()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;

    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;

    for (int i = 1; i < N; ++i)
        pr[i] = (pr[i - 1] + rf[i] * 1LL * f[i - 1]) % M;

    cin >> n;

    for (int q = (n - 1) / 2 + 1; q <= n; ++q)
    {
        u[q] = (f[q - 1] * 1LL * (pr[q - 1] - pr[(n - 1) / 2])) % M;
        u[q] = (f[q - 1] - u[q]) % M;
        u[q] = (u[q] + M) % M;
    }

    /*cout << u[n] << ' ';
    for (int i = 2; i <= n; ++i)
    {
        for (int q = (n - 1) / 2 + 1; q <= n - i + 1; ++q)
        {
            int yans = (f[n - i] * 1LL * (i - 1)) % M;
            yans = (yans * 1LL * f[n - q - 1]) % M;
            yans = (yans * 1LL * u[q]) % M;
            yans = (yans * 1LL * rf[q - 1]) % M;
            yans = (yans * 1LL * rf[n - i - q + 1]) % M;
            ans[i] = (ans[i] + yans) % M;
        }
        cout << ans[i] << ' ';
    }
    cout << "\n";*/

    vector<int> v1;
    v1.assign(n + 1, 0);
    for (int q = (n - 1) / 2 + 1; q <= n; ++q)
    {
        v1[q] = (f[n - q - 1] * 1LL * u[q]) % M;
        v1[q] = (v1[q] * 1LL * rf[q - 1]) % M;
    }

    vector<int> v2;
    v2.assign(n + 1, 0);
    for (int i = 0; i <= n; ++i)
        v2[i] = rf[i];

    ntt<M> F;
    vector<int> v = F.multiply(v1, v2);

    ans[1] = u[n];
    for (int i = 2; i <= (n - 1) / 2 + 1; ++i)
    {
        ans[i] = v[n - i + 1];
        ans[i] = (ans[i] * 1LL * f[n - i]) % M;
        ans[i] = (ans[i] * 1LL * (i - 1)) % M;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}