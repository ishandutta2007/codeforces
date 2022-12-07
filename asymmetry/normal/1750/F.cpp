#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<'\n';}(x)
#else
#define debug(...) {}
#endif

int mod;

int add(int a, int b) {
	a += b;
	return a >= mod ? a - mod : a;
}
int sub(int a, int b) {
	return add(a, mod - b);
}
int mul(int a, int b) {
	return int(a * LL(b) % mod);
}
int powi(int a, int b) {
	for(int ret = 1;; b /= 2) {
		if(b == 0)
			return ret;
		if(b & 1)
			ret = mul(ret, a);
		a = mul(a, a);
	}
}
int inv(int x) {
	return powi(x, mod - 2);
}
struct BinomCoeff {
	vector<int> fac, rev;
	BinomCoeff(int n) {
		fac = rev = vector(n + 1, 1);
		FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
		rev[n] = inv(fac[n]);
		for(int i = n; i > 0; --i)
			rev[i - 1] = mul(rev[i], i);
	}
	int operator()(int n, int k) {
		return mul(fac[n], mul(rev[n - k], rev[k]));
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n >> mod;
    vector<int> odp(n + 1), pref_odp(n + 1);
    vector dp(n + 1, vector(n + 2, 0));
    auto step_dp = dp;

    vector<int> pow2(n + 1);
    pow2[0] = 1;
    pow2[1] = 2;
    odp[1] = 1;
    pref_odp[1] = 1;
    FOR (i, 2, n) {
        pow2[i] = add(pow2[i - 1], pow2[i - 1]);
        odp[i] = pow2[i - 2];
        FOR (j, 1, i) {
            dp[i][j] = add(dp[i][j], mul(pref_odp[max(0, (i - j * 2 - 1) / 2)], odp[j]));
        }
        debug(i, odp[i]);
        debug(dp[i]);
        FOR (j, 1, i - 1) {
            if (i - j * 2 - 2 > 0) {
                dp[i][j] = add(dp[i][j], mul(odp[j], step_dp[i - j * 2 - 2][1]));
            }
            odp[i] = sub(odp[i], dp[i][j]);
        }
        debug(dp[i]);
        pref_odp[i] = add(pref_odp[i - 1], odp[i]);
        int pref_sum = 0;
        FOR (j, 1, n) {
            pref_sum = add(pref_sum, dp[i][j]);
            step_dp[i][j] = add(step_dp[i - 1][j + 1], pref_sum);
        }
    }
    debug(odp);
    cout << odp[n] << endl;
}