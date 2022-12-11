

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

const int maxp = 1000100;
const int mod = 1000000007;

int v[maxp];

int main () {
	int p,k,res=1;
	scanf("%d%d", &p, &k);
	if (k==1) {
		FOR(i,p) res=1LL*res*p % mod;
		printf("%d\n", res);
		return 0;
	}
	FORI(i,p-1) if (!v[i]) {
		res = 1LL*res*p % mod;
		int cur = i;
		while (!v[cur]) {
			v[cur] = 1;
			cur = 1LL*cur*k % p;
		}
	}
	printf("%d\n", res);
	return 0;
}