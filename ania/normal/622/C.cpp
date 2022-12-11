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

vi q[1000100];

int cnt(int x, int l, int r) {
	int L = lower_bound(q[x].begin(), q[x].end(), l) - q[x].begin();
	int R = lower_bound(q[x].begin(), q[x].end(), r) - q[x].begin();
	return r-l-R+L;
}

int main() {
	int n,m,a;
	scanf("%d%d", &n, &m);
	FOR(i,n) {
		scanf("%d", &a);
		q[a].push_back(i);
	}
	FOR(i,m) {
		int l,r,x;
		scanf("%d%d%d", &l, &r, &x);
		l--;
		if (cnt(x,l,r) == 0) printf("-1\n");
		else {
			while (l+1 < r) {
				int mid = (l+r)/2;
				int L = cnt(x, l, mid);
				if (L>0) r=mid;
				else l=mid;
			}
			printf("%d\n", l+1);
		}
	}
	return 0;
}