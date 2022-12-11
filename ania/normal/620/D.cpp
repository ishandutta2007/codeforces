#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 2020;

ll res, D;
vi best;
int a[maxn], b[maxn];
pair<ll, pii> x[maxn*maxn], y[maxn*maxn];

void add(int i, int j) {
	best.clear();
	best.pb(x[i].se.fi);
	best.pb(y[j].se.fi);
	if (x[i].se.se != -1) {
		best.pb(x[i].se.se);
		best.pb(y[j].se.se);
	}
}
void gener(int A, int B) {
	sort(x,x+A); sort(y,y+B);
	for (int i = 0, j = 0; i < A; i++) {
		while (j<B && D+y[j].fi*2 < x[i].fi*2) j++;

		if (j<B) {
			ll d = x[i].fi-y[j].fi;
			assert(D>=d*2);
			if (D-d*2 < res) {
				res=D-d*2;
				add(i,j);
			}
		}

		if (j>0) {
			ll d = x[i].fi-y[j-1].fi;
			assert(d*2>=D);
			if (d*2-D < res) {
				res = d*2-D;
				add(i,j-1);
			}
		}
	}
}

int main() {
	int A,B;
	scanf("%d", &A);
	FOR(i,A) scanf("%d", &a[i]);
	scanf("%d", &B);
	FOR(i,B) scanf("%d", &b[i]);

	ll SA=0, SB=0;
	FOR(i,A) SA += a[i];
	FOR(i,B) SB += b[i];
	D = SA-SB; // D>=0
	res = D<0?-D:D;

	FOR(i,A) x[i]=mp(a[i], mp(i,-1));
	FOR(i,B) y[i]=mp(b[i], mp(i,-1));
	gener(A,B);

	int qx=0, qy=0;
	FOR(i,A) FOR(j,i) x[qx++] = mp(a[i]+a[j], mp(j,i));
	FOR(i,B) FOR(j,i) y[qy++] = mp(b[i]+b[j], mp(j,i));
	gener(qx,qy);

	assert(res>=0);

	cout << res << " " << SZ(best)/2 << "\n";
	//printf("%I64d\n%d\n", res, SZ(best)/2);
	FOR(i,SZ(best)) cout << best[i]+1 << " ";
	cout << "\n";
	//printf("%d ", best[i]+1);
	//printf("\n");
	return 0;
}