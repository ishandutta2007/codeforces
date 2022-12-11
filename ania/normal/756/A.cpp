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

const int N = 200200;

int p[N], b[N], vis[N];

void test() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &p[i]);
	FOR(i,n) scanf("%d", &b[i]);
	FOR(i,n) p[i]--;
	int res=0;
	FOR(i,n) if (!vis[i]) {
		res++;
		int u=i;
		while (!vis[u]) {
			vis[u]=1;
			u=p[u];
		}
	}
	if (res==1) res=0;
	int B=0;
	FOR(i,n) B+=b[i];
	res += 1-B%2;
	printf("%d\n", res);
}

int main() {
	test();
	return 0;
}