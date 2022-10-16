#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

#define f0r(i,a) for(int i = (0); i<(a); ++i)
#define f1r(i,a,b) for(int i =(a); i<(b); ++i)
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
struct mi{
    int val;
    explicit operator int() const { return val; }
	mi() { val = 0; }
    mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) {
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) {
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) {
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
const int MAXN = 205;
const int MAXK = 1005;
/// considered, open groups, imbalance
mi dp[MAXN][MAXN][MAXK];
int main(){
    // cin.sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vi a(n);
    f0r(i, n) cin >> a[i];
    sort(all(a));
    f0r(i, n){
        if(i == 0){
            dp[0][1][0] = 1;
            dp[0][0][0] = 1;
            continue;
        }
        f0r(j, n+1){
            f0r(im, k+1){
                mi bef = dp[i-1][j][im];
                if(bef == 0) continue;
                int nxt = im + j*(a[i] - a[i-1]);
                if(nxt>k) continue;
                dp[i][j][nxt] += bef;
                dp[i][j][nxt] += j*bef;
                dp[i][j+1][nxt] += bef;
                if(j) dp[i][j-1][nxt] += j*bef;
            }
        }
    }
    mi ans = 0;
    f0r(im, k+1) ans += dp[n-1][0][im];
    cout << ans.val << endl;
    return 0;
}