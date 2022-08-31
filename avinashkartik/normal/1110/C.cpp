#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;

vll adj[MAXN]; ll visit[MAXN] = {};
int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x, m, y, k;
string s;

// <------------- Implement Functions Here ----------> //

bool isval(ll n) {
	return (n&(n+1)) == 0;
}

bool isprime(ll x) {
	if(x <= 1 ) return false;
	for(ll i=2;i*i <=x;i++) {
		if(x%i == 0) return false;
	}
	return true;
}


// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n;
	ll ans = 0;
	bool val = isval(n);
	if(val) {
		for(ll i=2;i*i<=n;i++) {
			if(n%i == 0) {
				if(isprime(i)) {
					cout<<n/i;
					newl;
					return;
				}
			}
		}

		cout<<1;newl;
	}
	else {
		ll cou = 0;
		while(n) {
			cou++;
			n/=2;
		}
		cout<<(ll)(pow(2,cou)-1);newl;
	}
}

int main() {
	fastio; randomINT;
	cin>>T;
	while (T--) {
		MAIN();
	}
	return 0;
}