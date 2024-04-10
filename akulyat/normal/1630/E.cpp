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

bool viv = false;
int n;
vector<int> v;

vector<zet> f;

void prepare() {
	f.resize(1, 1);
	for (int i = 1; i < ml + 100; i++)
		f.push_back(f.back() * i);	
}

zet counter(vector<int> &cnt, int sum, int val) {
	zet n = sum * val;

	zet prob = 0;
	for (auto i: cnt) {
		zet k = i * val;
		prob += k * (k - 1) / 2;
	}
	prob /= n * (n - 1) / 2;	

	zet ans = n;
	ans -= zet(n) * prob;
	return ans;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;

	vector<int> cnt(n, 0);
	vector<int> nonz_cnt;
	for (auto i : v)
		cnt[i]++;
	if (cnt[v[0]] == n) {
		cout << "1\n";
		return;
	}
	int val = cnt[0];
	for (auto i : cnt)
		val = __gcd(val, i);
	for (auto &i : cnt)
		i /= val;
	for (auto i : cnt)
		if (i)
			nonz_cnt.push_back(i);		
	int sum = n / val;

	if (viv)
		cout << "val = " << val << endl;
	vector<zet> ans(val + 1, 0);

	vector<zet> uniq(val + 1);
	for (int i = 1; i < uniq.size(); i++) {
		uniq[i] = f[sum * i];
		for (auto j : nonz_cnt)
			uniq[i] /= f[j * i];
	}

	vector<vector<int>> divs(val + 10);

	for (int i = 1; i <= val; i++) {
		if (val % i == 0) {
			zet add = counter(nonz_cnt, sum, i);
			ans[i] = add;

			for (auto d : divs[i]) {
				zet n = sum * d;
				zet N = sum * i;

				if (viv)
					cout << "\t\twas " << ans[i] << ' ' << uniq[i] << '\n'; 
				zet res = ans[i];
					res *= uniq[i];
						zet reps = (uniq[d]);
						res -= ans[d] * (i / d) * reps;
						uniq[i] -= reps;
					res /= uniq[i];
				ans[i] = res;
				if (viv)
					cout << "\t\t now " << ans[i] << ' ' << uniq[i] << '\n'; 
			}
			if (viv)
				cout << "\tans[" << i << "] = " << ans[i] << ' ' << uniq[i] << '\n';

			for (int j = 2 * i; j <= val; j += i)
				divs[j].push_back(i);
		}
	}
	zet res = 0;
	zet w = 0;
	for (int i = 1; i <= val; i++) 
		if (val % i == 0) {
			zet lw = uniq[i] / (sum * i);
			if (viv)
				cout << "\tsee " << i << ": " << ans[i] << ' ' << lw << '\n';
			res += ans[i] * (val / i) * lw;	
			w += lw;
		}
	res /= w;
	cout << res << '\n';
}

int main() {
	prepare();
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}