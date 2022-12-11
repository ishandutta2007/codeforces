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

long long n;

int main() {
	cin >> n;
	n %= 360;
	n = 360-n;
	n %= 360;
	int B=361, r=0;
	FOR(i,4) {
		int d = min(abs(n), 360-abs(n));
		if (d<B) {
			B=d;
			r=i;
		}
		n += 90;
		n %= 360;
	}
	cout << r;
	return 0;
}