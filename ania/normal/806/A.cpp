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

void test() {
	ll x,y,p,q;
	cin >> x>>y>>p>>q;
	if (p==q || p==0) {
		if (p==q && x==y) cout << "0\n";
		else if (p==0 && x==0) cout << "0\n";
		else cout << "-1\n";
		return;
	}
	ll b1 = (q*x-p*y + p-1) / p;
	ll b2 = (p*y-q*x + q-p-1) / (q-p);
	ll b = max(b1,b2);
	if ((b+y)%q) b += q-(b+y)%q;
	cout << b << "\n";
	return;
	ll r=y%q, m=y/q;
	ll n1 = (m*p-x-r + (q-p-1)) / (q-p), n2 = (x-m*p + p-1) / p;
	ll n = max(n1, n2);
	ll ret = n * q - r;
	cout << ret << "\n";
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) test();
	return 0;
}