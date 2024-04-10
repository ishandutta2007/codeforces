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

const int mod = 1000000007;

struct m{
	int t[2][2];
	m() {FOR(i,2) FOR(j,2) t[i][j]=0;}
	m operator* (m x) {
		m res;
		FOR(i,2) FOR(j,2) FOR(k,2) res.t[i][j]=(1LL*t[i][k]*x.t[k][j]+res.t[i][j])%mod;
		return res;
	}
};

m one;

m qpow(m a, ll n) {
	if (n==0) return one;
	m b=qpow(a,n/2);
	b=b*b;
	if (n&1) b=b*a;
	return b;
}

int main() {
	ll n;
	one.t[0][0]=one.t[1][1]=1;
	cin >> n;
	m x;
	x.t[0][0]=x.t[1][1]=3;
	x.t[1][0]=x.t[0][1]=1;
	x=qpow(x,n);
	printf("%d\n", x.t[0][0]);
	return 0;
}