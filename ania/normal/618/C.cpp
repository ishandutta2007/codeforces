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

const int maxn = 100100;

int x[maxn], y[maxn];

long long mabs(long long x) {
	if (x<0) return -x;
	return x;
}

long long area(int a, int b, int c) {
	int ax = x[a]-x[c], ay = y[a]-y[c], bx = x[b]-x[c], by = y[b]-y[c];
	return mabs(1LL*ax*by-1LL*ay*bx);
}

void test() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d%d", &x[i], &y[i]);
	int a=0, b=1, c=2;
	while (area(a,b,c)==0) c++;
	for (int d = 0; d < n; d++) if (d!=a && d!=b && d!=c) {
		ll A = area(d,b,c), B = area(a,d,c), C = area(a,b,d), D = area(a,b,c);
		if (A+B+C != D) continue;
		if (A!=0) { a=d; continue; }
		if (B!=0) { b=d; continue; }
		c=d;
	}
	printf("%d %d %d\n", a+1, b+1, c+1);
}

int main() {
	test();
	return 0;
}