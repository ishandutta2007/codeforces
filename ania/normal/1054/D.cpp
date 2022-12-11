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

ll seg(int n) {
	return 1LL * n * (n-1) / 2;
}

int a[N], b[N];
map<int, int> cnt;

int main() {
	int n,k,m;
	scanf("%d%d", &n, &k);
	ll res = seg(n+1);
	m = (1<<k) - 1;
	FORI(i,n) scanf("%d", &a[i]);
	cnt[0] = 1;
	FORI(i,n) {
		b[i] = a[i] ^ b[i-1];
		cnt[min(b[i], b[i]^m)]++;
	}
	for (auto it : cnt) {
		int tot = it.second;
		int lo = tot/2, hi = tot-lo;
		res -= seg(lo);
		res -= seg(hi);
	}
	cout << res << "\n";
	return 0;
}