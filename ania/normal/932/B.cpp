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

const int M = 1000003;

int t[10][M+3], d[M+3];

void test() {
	int l,r,k;
	scanf("%d%d%d", &l, &r, &k);
	printf("%d\n", t[k][r] - t[k][l-1]);
}

int mul(int x) {
	int res=1;
	while (x) {
		if (x%10) res *= x%10;
		x /= 10;
	}
	return res;
}

int main() {
	FORI(i,9) d[i]=i;
	for (int i = 10; i <= M; i++) d[i] = d[mul(i)];
	FORI(j,9) FORI(i,M) {
		t[j][i] = t[j][i-1] + (d[i] == j);
	}
	int tt;
	scanf("%d", &tt);
	while (tt--) test();
	return 0;
}