#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<bool> vbool;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = b-1; i >= a; i--)
#define FIN ios::sync_with_stdio(false);cin.tie(0);
#define db(x) cout<<#x<<" = "<<x<<"\n"
#define all(v) v.begin(),v.end()
#define modulo(a,b) ((a%b)+b)%b
#define F first
#define S second
#define INF 1000000010
#define INFLL 1000000000000000000
#define eps 0.000000001
#define mod 1000000007
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//=======================//


string path;
int n;

#define left {-1,0};
#define right {1,0};
#define up {0,1};
#define down {0,-1};

bool equal(pi p1, pi p2) {
	return p1.F == p2.F && p1.S == p2.S;
}

pi operator+(const pi p1, const pi p2) {
	return {p1.F + p2.F, p1.S + p2.S};
}

pi f(char c) {
	if(c == 'L') return left;
	if(c == 'D') return down;
	if(c == 'U') return up;
	if(c == 'R') return right;
}

void solve() {
	cin >> path;
	n = (int)path.size();
	pi origen = {0,0};
	pi obstacle = {0,0};
	for(int i = 0; i < n; i++) {
		obstacle = obstacle + f(path[i]);
		if(obstacle == origen) continue;
		pi pos = origen;
		for(int j = 0; j < n; j++) {
			pi next = pos + f(path[j]);
			if(next != obstacle) {
				pos = next;
			}
		}
		if(pos == origen) {
			cout << obstacle.first << " " << obstacle.second << "\n";
			return;
		}
	}
	cout << "0 0\n";
}



int main () {
	FIN
	int t; cin >> t; while(t--) solve();
	return 0;
}