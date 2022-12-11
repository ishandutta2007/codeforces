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

int main() {
	ll a,b;
	int res=0;
	cin >> a >> b;
	for (int len=2; len<=60; len++) {
		for (int pos = 0; pos<len-1; pos++) {
			long long cur = (1LL<<len)-1;
			cur -= 1LL<<pos;
			if (a <= cur && cur <= b) res++;
		}
	}
	printf("%d\n",res);
	return 0;
}