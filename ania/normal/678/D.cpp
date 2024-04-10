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

const ll M = 1000000007LL;

ll qpow(ll a, ll n) {
	if (n==0) return 1;
	ll b = qpow(a, n/2);
	b = b*b%M;
	if (n%2) b=a*b%M;
	return b;
}

ll s(ll a, ll n) {
	if (a==1) return n%M*a%M;
	ll P = qpow(a,n)-1, Q = a-1;
	Q = qpow(Q, M-2);
	return P*Q%M;
}

int main() {
	ll a,b,n,x;
	cin >> a >> b >> n >> x;
	ll A = qpow(a,n);
	A = A*x%M;
	ll B = s(a,n);
	B = B*b%M;
	cout << (A+B)%M << "\n";
	return 0;
}