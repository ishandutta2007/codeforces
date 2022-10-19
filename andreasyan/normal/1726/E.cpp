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
const int N = 600005, M = 998244353;

void por()
{
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i)
        v.push_back(i);

    int q = 0;
    set<int> s;
    do
    {
        vector<int> u;
        u.assign(sz(v), 0);
        for (int i = 0; i < n; ++i)
            u[v[i]] = i;
        bool z = true;
        for (int i = 0; i < n; ++i)
        {
            if (abs(v[i] - u[i]) > 1)
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            ++q;
            for (int i = 0; i < n; ++i)
            {
                int x = i;
                int q = 0;
                while (1)
                {
                    ++q;
                    x = v[x];
                    if (x == i)
                        break;
                }
                s.insert(q);
            }
            continue;
            for (int i = 0; i < n; ++i)
                cout << v[i] + 1;
            cout << endl;
            for (int i = 0; i < n; ++i)
                cout << u[i] + 1;
            cout << endl << endl;
        }
    } while (next_permutation(all(v)));

    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    cout << q << endl;
}

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
int ff[N], rff[N];
int ast2[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;

    ff[0] = ff[1] = 1;
    for (int i = 2; i < N; ++i)
        ff[i] = (ff[i - 2] * 1LL * i) % M;

    ast2[0] = 1;
    for (int i = 1; i < N; ++i)
        ast2[i] = (ast2[i - 1] * 2) % M;
}

int C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return (f[n] * 1LL * rf[k]) % M * rf[n - k] % M;
}

ntt<M> F;
int n;

void solv()
{
    cin >> n;

    vector<int> v1, v2;
    v1.assign(n + 5, 0);
    v2.assign(n + 5, 0);
    for (int q = 0; q * 2 <= n; ++q)
    {
        if (q)
            v1[q * 2] = (ff[2 * q - 1] * 1LL * rf[2 * q]) % M;
        else
            v1[q * 2] = rf[2 * q];
    }
    for (int t = 0; t * 4 <= n; ++t)
    {
        if (t)
            v2[t * 4] = (ff[2 * t - 1] * 1LL * C(n - 2 * t, 2 * t)) % M;
        else
            v2[t * 4] = 1;
        v2[t * 4] = (v2[t * 4] * 1LL * ast2[t]) % M;
        v2[t * 4] = (v2[t * 4] * 1LL * f[n - t * 4]) % M;
    }

    vector<int> v = F.multiply(v1, v2);

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = (ans + v[i] * 1LL * rf[n - i]) % M;
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    //por();
    //return 0;

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}