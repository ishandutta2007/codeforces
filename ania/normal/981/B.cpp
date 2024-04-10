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

map<int,int> v;
int a[N], b[N], x[N], y[N];

int main() {
	int n,m;
	ll res = 0;
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d%d", &a[i], &x[i]);
		v[a[i]] = x[i];
	}
	scanf("%d", &m);
	FOR(i,m) {
		scanf("%d%d", &b[i], &y[i]);
		v[b[i]] = max(v[b[i]], y[i]);
	}
	for (map<int,int> :: iterator i = v.begin(); i != v.end(); i++) res += i->second;
	cout << res << "\n";
	return 0;
}