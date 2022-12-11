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

const int N = 100100;
const ll mx = 1000000100000000LL;

int n,m,k;
int cnt[N], a[N];
ll p[N], tmp[N];
map<ll,int> val;
set<ll> used;

void add(ll x) {
	int y=val[x];
	cnt[y]++;
}

ll get(ll x) {
	if (val.find(x)==val.end()) return 0;
	int y=val[x];
	return cnt[y];
}

int main() {
	scanf("%d%d", &n, &k);
	FOR(i,n) scanf("%d", &a[i]);
	p[0]=0;
	FORI(i,n) p[i]=p[i-1]+a[i-1];
	FOR(i,n+1) tmp[i]=p[i];
	sort(tmp,tmp+n+1);
	FOR(i,n+1) if (val.find(tmp[i]) == val.end()) val[tmp[i]]=m++;
	long long x=1, res=0;
	while (x < mx && x > -mx) {
		if (used.find(x) != used.end()) break;
		used.insert(x);
		FOR(i,n+1) {
			res += get(p[i]-x);
			add(p[i]);
		}
		FOR(i,m) cnt[i]=0;
		x *= k;
	}
	cout << res << "\n";
	return 0;
}