#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int main() {
	ll n,k;
	cin >> n >> k;
	k=(k+1)/2;
	while (n > 1 && k >= 1) {
		ll x=1;
		for (ll d=2; d*d <= n; d++) if (n%d==0) {
			x *= d-1;
			n /= d;
			while (n%d==0) {
				x *= d;
				n /= d;
			}
		}
		if (n>1) x *= n-1;
		n = x;
		k--;
	}
	cout << (n%1000000007) << "\n";
	return 0;
}