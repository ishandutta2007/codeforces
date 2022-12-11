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
const int M = 1<<17;

int n;
int a[N];
int Tm[M*2+13];
ll Ts[M*2+13];

ll get_sum(int le, int ri) {
	le += M;
	ri += M;
	ll res = Ts[le];
	while (le+1 < ri) {
		if (le % 2 == 0) res += Ts[le+1];
		if (ri % 2 == 1) res += Ts[ri-1];
		le /= 2;
		ri /= 2;
	}
	return res;
}

int get_max(int le, int ri) {
	le += M;
	ri += M;
	int res = Tm[le];
	while (le+1 < ri) {
		if (le % 2 == 0) if (a[Tm[le+1]] > a[res]) res = Tm[le+1];
		if (ri % 2 == 1) if (a[Tm[ri-1]] > a[res]) res = Tm[ri-1];
		le /= 2;
		ri /= 2;
	}
	return res;
}

void update(int pos) {
	Ts[pos+M] = a[pos];
	pos += M;
	while (pos > 1) {
		pos /= 2;
		int le = pos * 2, ri = pos * 2 + 1;
		if (a[Tm[le]] > a[Tm[ri]]) Tm[pos] = Tm[le];
		else Tm[pos] = Tm[ri];
		Ts[pos] = Ts[le] + Ts[ri];
	}
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) {
		Tm[M+i] = i;
		Ts[M+i] = a[i];
	}
	for (int i = M-1; i >= 1; i--) {
		int le = i*2, ri = i*2+1;
		if (a[Tm[le]] > a[Tm[ri]]) Tm[i] = Tm[le];
		else Tm[i] = Tm[ri];
		Ts[i] = Ts[le] + Ts[ri];
	}
	FOR(ii,m) {
		int tt;
		scanf("%d", &tt);
		if (tt == 1) {
			int le, ri;
			scanf("%d%d", &le, &ri);
			le--;
			printf("%I64d\n", get_sum(le, ri));
		} else if (tt == 2) {
			int le, ri, x;
			scanf("%d%d%d", &le, &ri, &x);
			le--;
			int pos;
			while (a[pos = get_max(le, ri)] >= x) {
				a[pos] %= x;
				update(pos);
			}
		} else {
			int pos, x;
			scanf("%d%d", &pos, &x);
			pos--;
			a[pos] = x;
			update(pos);
		}
	}
	return 0;
}