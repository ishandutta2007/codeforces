#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int main() {
	int n,a,last=0;
	set<int> s;
	vector<pi> res;
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d", &a);
		if (s.find(a) != s.end()) {
			res.pb(mp(last, i));
			last=i+1;
			s.clear();
		} else {
			s.insert(a);
		}
	}
	if (res.size()==0) {
		printf("-1\n");
	} else {
		if (!s.empty()) res.back().se=n-1;
		printf("%d\n", SZ(res));
		for (int i = 0; i < SZ(res); i++)
			printf("%d %d\n", res[i].fi+1, res[i].se+1);
	}
	return 0;
}