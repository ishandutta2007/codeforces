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

const int N = 200100;
const int mod = 1000000007;

int qpow(int a, int n) {
	if (n==0) return 1;
	int b=qpow(a,n/2);
	b=1LL*b*b%mod;
	if (n&1) b=1LL*a*b%mod;
	return b;
}

int inv(int x) {
	return qpow(x,mod-2);
}

int n;
int a[N], b[4][N];


inline int f(int x, int y, int s) {
	int r = s&1 ? x-y : x+y;
	if (r<0) r+=mod;
	if (r>=mod) r-=mod;
	return r;
}

int go() {
	int m = n, s = 0;
	FOR(i,n) b[0][i] = a[i];
	int it = 1;
	while (m%4 != 1) {
		m--;
		FOR(i,m) {
			b[it][i] = f(b[it-1][i], b[it-1][i+1], s+i);
		}
		s = (s+m)%2;
		it++;
	}
	FOR(i,m) a[i]=b[it-1][i];
	return m;
}

void test() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	n=go();
	int m=n/2;
	int cur=1;
	int res=0;
	//printf("n=%d\n", n);
	//FOR(i,n) printf("%d ", a[i]);
	printf("\n");
	for (int i=0; 2*i<n; i++) {
		//printf("adding %d * %d\n", a[2*i], cur);
		res = (1LL * cur * a[2*i] + res) % mod;
		cur = 1LL * cur * (m-i) % mod;
		cur = 1LL * cur * inv(i+1) % mod;
	}
	printf("%d\n",res);
}

int main() {
	int ttn=1;
	while (ttn--) test();
	return 0;
}