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

long long f(int x) {
	return n/x;
}

int main() {
	cin >> n;
	cout << n - n/2 - n/3 - n/5 - n/7 + n/6 + n/10 + n/14 + n/15 + n/21 + n/35 - n/30 - n/42 - n/70 - n/105 + n/210;
	return 0;
}