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

const int N = 555;

int n,m;
int a[N][N], b[N][N];

void test() {
	scanf("%d%d", &n, &m);
	FOR(i,n) FOR(j,m) scanf("%d", &a[i][j]);
	FOR(i,n) FOR(j,m) scanf("%d", &b[i][j]);
	FOR(i,n-1) FOR(j,m-1) if (a[i][j] != b[i][j]) {
		b[i][j] ^= 1;
		b[i+1][j] ^= 1;
		b[i][j+1] ^= 1;
		b[i+1][j+1] ^= 1;
	}
	FOR(i,n) FOR(j,m) if (a[i][j] != b[i][j]) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}