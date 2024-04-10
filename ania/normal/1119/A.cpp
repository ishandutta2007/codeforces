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

const int N = 300300;

int a[N];

void test() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	if (a[0] != a[n-1]) {
		printf("%d\n", n-1);
		return;
	}
	int res = 0;
	FOR(i,n) if (a[i] != a[0]) {
		res = max(res, i);
		res = max(res, n-i-1);
	}
	printf("%d\n", res);
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}