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

ll n,a,b,p,q;

ll f(ll N, ll A) {
	return N/A;
}

int main() {
	cin >> n >> a >> b >> p >> q;
	if (p>q) {
		swap(a,b);
		swap(p,q);
	}
	ll A = f(n,a), B = f(n,b), C = f(n,a/__gcd(a,b)*b);
	cout << (A-C)*p + B*q << "\n";
	return 0;
}