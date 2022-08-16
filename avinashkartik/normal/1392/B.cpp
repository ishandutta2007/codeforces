// <------------- Template -----------------------> //

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
*/

#pragma optimization_level 3   									//Comment optimisations for an interatcive problem - use endl
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
typedef pair<ll ,ll> 			pll;
typedef pair<ld,ld> 			pld;
typedef unordered_map<ll,ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5+7;
const ll 	MAX7 	= 	1e+7+7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9+7;
const ll 	N 		= 	2*1e6;

vll adj[N];ll visit[N]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

// <------------- Declare Variables Here ------------> //

ll T=1;
ll n,x,y,m,k;
string s,t;
vll a,b,p,ans;
// <------------- Implement Functions Here ----------> //

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n >> k;
	a = vll(n);
	for(ll i=0;i<n;i++) cin>>a[i];
	//sort(all(a));
	//reverse(all(a));
	ll mini = *min_element(all(a));
	ll maxi = *max_element(all(a));

	//DISP(a);
	if(n==1) {
		cout<<0;newl;return;
	}

	if(k&1) {
		for(ll i=0;i<n;i++) {
			a[i] = maxi - a[i];
		}
	}
	else {
		for(ll i=0;i<n;i++) {
			a[i] = maxi - a[i];
		}
		maxi = *max_element(all(a));
		for(ll i=0;i<n;i++) {
			a[i] = maxi - a[i];
		}
		
	}
	DISP(a);
}

int main() {
	fastio;randomINT;
	cin>>T;
	while(T--) {
		MAIN();
	}
	return 0;
}