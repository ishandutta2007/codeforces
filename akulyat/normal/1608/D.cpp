#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


template<int md, int maxpw = 23>
struct NTT {
    int mul(int a, int b) {
        return a * (ll)b % md;
    }
    int sum(int a, int b) {
        a += b;
        if (a >= md) a -= md;
        return a;
    }
    int diff(int a, int b) {
        a -= b;
        if (a < 0) a += md;
        return a;
    }
    int mpow(int a, int n) {
        int ans = 1;
        for (; n > 0; n >>= 1, a = mul(a, a))
            if (n & 1) ans = mul(ans, a);
        return ans;
    }
    int lst(int n) const { return 31 - __builtin_clz(n); }
    vector<int> sq;
    NTT() {
        int rt = 2;
        while (mpow(rt, 1 << maxpw) != 1 || mpow(rt, 1 << maxpw - 1) == 1) ++rt;
        sq = vector<int>(maxpw + 1);
        sq[maxpw] = rt;
        for (int i = maxpw - 1; i >= 0; --i)
            sq[i] = mul(sq[i + 1], sq[i + 1]);
    }
    vector<int> ind;
    void dft(vector<int> &a, int n) {
        int LOG = lst(n);
        if (sz(ind) != n) {
            ind.resize(n);
            for (int i = 1; i < n; ++i) {
                int l = lst(i);
                ind[i] = ind[i ^ (1 << l)] | (1 << LOG - 1 - l);
            }
        }
        vector<int> cp(n);
        for (int i = 0; i < n; ++i) cp[i] = a[ind[i]];
        swap(a, cp);
        for (int len = 2; len <= n; len *= 2) {
            int w = sq[lst(len)];
            int l2 = len >> 1, msk = l2 - 1;
            for (int i = 0; i < n; i += len) {
                int c = 1;
                for (int j = 0; j < l2; ++j) {
                    int x = a[i + j], y = mul(a[i + l2 + j], c);
                    a[i + j] = sum(x, y);
                    a[i + j + l2] = diff(x, y);
                    c = mul(c, w);
                }
            }
        }
    }
    vector<int> multiply(vector<int> a, vector<int> b) {
        int n = 1;
        while (n < sz(a) || n < sz(b)) n *= 2;
        n *= 2;
        a.resize(n);
        b.resize(n);
        dft(a, n);
        dft(b, n);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = mul(a[i], b[i]);
        dft(ans, n);
        reverse(ans.begin() + 1, ans.end());
        int inv = mpow(n, md - 2);
        for (auto &i : ans) i = mul(i, inv);
        return ans;
    }
};

bool viv = false;
int n;
vector<pii> v;

struct zet {
    int val;
    explicit operator int() const { return val; }
    zet(ll x = 0) { val = (x >= -mod && x < mod ? x : x % mod); if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, mod - 2); }
    zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend zet operator+(zet a, const zet &b) { return a += b; }
    friend zet operator-(zet a, const zet &b) { return a -= b; }
    friend zet operator-(zet a) { return 0 - a; }
    friend zet operator*(zet a, const zet &b) { return a *= b; }
    friend zet operator/(zet a, const zet &b) { return a /= b; }
    friend istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
    friend bool operator<(zet const &a, zet const &b) { return a.val < b.val; }
};

vector<zet> f, fi;

void prepare() {
	f.push_back(1);
	for (int i = 1; i < 300 * kk; i++)
		f.push_back(f.back() * i);
	for (auto i : f)
		fi.push_back(inv(i));
}

zet C(int n, int k) {
	if (n < 0 || k < 0 || n - k < 0)
		return 0;
	zet res = f[n];
	res /= f[k];
	res /= f[n - k];
	return res;
}

void solve() {
	prepare();
	cin >> n;
	v.resize(n);
	for (auto &[l, r] : v) {
		string s;
		cin >> s;
		if (s[0] == '?')
			l = -1;
		else
			l = (s[0] == 'B');
		if (s[1] == '?')
			r = -1;
		else
			r = (s[1] == 'B');
	}

	int ww = 0, w = 0;
	int bb = 0, b = 0;
	int wb = 0, u = 0;
	for (auto &[l, r] : v) {
		if (l == 0 && r == 0) {
			ww++;
		}
		if (l == -1 && r == 0) {
			w++;
		}
		if (l == 0 && r == -1) {
			w++;
		}
		if (l == 1 && r == 1) {
			bb++;
		}
		if (l == -1 && r == 1) {
			b++;
		}
		if (l == 1 && r == -1) {
			b++;
		}
		if (l == 1 && r == 0) {
			wb++;
		}
		if (l == 0 && r == 1) {
			wb++;
		}
		if (l == -1 && r == -1)
			u++;
	}

	int cw = 2 * ww + w + wb;
	int cb = 2 * bb + b + wb;
	if (max(cw, cb) > n) {
		cout << "0\n";		
		return;
	}


	zet ans = C((n - cw) + (n - cb), n - cw);

	zet bad = 0;
	if (ww == 0 && bb == 0) {
		bad = 1;
		for (int i = 0; i < u; i++)
			bad *= 2;

		int nice1 = 1;
		int nice2 = 1;
		for (auto &[l, r] : v) {
			if (l == 0)
				nice1 = 0;
			if (l == 1)
				nice2 = 0;
			if (r == 1)
				nice1 = 0;
			if (r == 0)
				nice2 = 0;
		}
		bad -= nice1;
		bad -= nice2;
	}
	ans -= bad;

	cout << ans << '\n';
}

int main() {
	viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}