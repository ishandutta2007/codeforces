#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

const int mod = 1000000007;

int qpow(int a, int n) {
	if (n==0) return 1;
	int b=qpow(a,n/2);
	b=1LL*b*b%mod;
	if (n&1) b=1LL*a*b%mod;
	return b;
}

int inv(int x) {
	return qpow(x, mod-2);
}

int k,pa,pb;
int d[1010][1010];
int dd;
int get(int a, int n) {
	if (a < k && n < k) return d[a][n];
	if (n >= k) return n;
	return n+a+dd;
}

int main() {
	scanf("%d%d%d", &k, &pa, &pb);
	int iv = inv(pa+pb);
	int da = 1LL * pa * iv % mod, db = 1LL * pb * iv % mod;
	int ib = inv(pb);
	dd = 1LL * pa * ib % mod;
	for (int a = k-1; a > 0; a--) for (int n = k-1; n >= 0; n--) {
		d[a][n] = (1LL * get(a+1, n) * da + 1LL * get(a, n+a) * db) % mod;
	}
	d[0][0] = 1LL * get(1,0) * da % mod * inv(mod+1-db) % mod;
	printf("%d\n", d[0][0]);
	return 0;
}