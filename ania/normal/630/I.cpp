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

long long n, r;

int main() {
	cin >> n;
	FOR(p,n-1) {
		long long c = 9*4;
		FOR(i,n-4) c*=4;
		if (p==0 || p==n-2) c = c*4/3;
		if (n==3) c /= 4;
		r += c;
	}
	cout << r;
	return 0;
}