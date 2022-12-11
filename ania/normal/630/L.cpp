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

int p[5] = {100, 10, 1000, 1, 10000};
int n,r,q;

int main() {
	cin >> n;
	while (n) {
		r += p[q]*(n%10);
		q++;
		n /= 10;
	}
	q=r;
	FOR(i,4) {
		r = 1LL * r * q % 100000;
	}
	printf("%05d\n", r);
	return 0;
}