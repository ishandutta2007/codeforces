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


// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x, m, y, k, z;
//string s, t;


// <------------- Implement Functions Here ----------> //

void rotate90(vector<string> &a) {
	vector<string> b(n);
	for(ll i=0;i<n;i++) b[i].resize(n);
	for(ll i=0;i<n;i++) {

		for(ll j=0;j<n;j++) {
			b[j][n-i-1] = a[i][j];
			//cout<<a[i][j]<<" ";
		}
	}
	a = b;
}

void mirror(vector<string> &a) {
	for(ll i=0;i<n;i++) {
		reverse(all(a[i]));
	}
}

void DISPPLAY(vector<string> &a) {
	for(auto it : a) {
		cout<<it;newl;
	}
	newl;
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n ;
	vector<string> s(n);
	vector<string> t0(n), t90(n), t180(n), t270(n);

	for(ll i=0;i<n;i++) {
		cin >> s[i];
	}

	for(ll i=0;i<n;i++) {
		cin>> t0[i];
		t90.resize(n);
		t180.resize(n);
		t270.resize(n);
	}

	/*for(ll i=0;i<n;i++) {
		for(ll j=0;j<n;j++) {
			t90[i][j] = t0[i][j];
		}
	}*/



	if(s == t0) {
		cout<<"Yes\n";
		return;
	}


	rotate90(t0); // 90
	


	if(s == t0) {
		cout<<"Yes\n";
		return;
	}

	rotate90(t0); // 180

	if(s == t0) {
		cout<<"Yes\n";
		return;
	}

	rotate90(t0); // 270

	if(s == t0) {
		cout<<"Yes\n";
		return;
	}

	rotate90(t0); //back to normal

	mirror(t0);

	if(s == t0) {
		cout<<"Yes\n";
		return;
	}

	rotate90(t0); // 90
	
	if(s == t0) {
		cout<<"Yes\n";
		return;
	}

	rotate90(t0); // 180

	if(s == t0) {
		cout<<"Yes\n";
		return;
	}

	rotate90(t0); // 270

	if(s == t0) {
		cout<<"Yes\n";
		return;
	}

	cout<<"No\n";
	
	
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}