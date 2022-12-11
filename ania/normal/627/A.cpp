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

ll ways(ll s, ll x, ll needcarry) {
	ll r=0;
	FOR(a,2) FOR(b,2) FOR(c,2) if ((a+b+c)%2==s && (a+b)%2==x && (a+b+c)/2==needcarry) r++;
	//printf("ways(%d %d %d) = %d\n", s, x, needcarry, r);
	return r;
}

int main() {
	ll s,x;
	cin >> s >> x;
	if (s%2 != x%2) {
		printf("0\n");
		return 0;
	}
	ll r=1;
	ll rm = x==s;
	while (s || x) {
		ll needcarry = (s/2%2) ^ (x/2%2);
		r *= ways(s%2, x%2, needcarry);
		s /= 2;
		x /= 2;
	}
	r -= rm*2;
	cout << r << "\n";
	return 0;
}