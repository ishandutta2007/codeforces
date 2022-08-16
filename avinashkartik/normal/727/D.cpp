
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
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	998244353;

// <------------- Declare Variables Here ------------> //

ll t = 1;
ll n;
string s;
// <------------- Implement Functions Here ----------> //// <------------- Start of main() -------------------> //

vector<string> removeDupWord(string str) 
{ 
   vector<string> val;
   string word = ""; 
   for (auto x : str) 
   { 
       if (x == ',') 
       { 
           //cout << word << endl; 
           val.pb(word);
           word = ""; 
       } 
       else
       { 
           word = word + x; 
       } 
   }  
   val.pb(word);
   return val;
   //cout << word << endl; 
}

void MAIN() {
	vll size(6);
	for(ll i=0;i<6;i++) cin>>size[i];
	map<ll,string> indx;

	indx[0] = "S";
	indx[1] = "M";
	indx[2] = "L";
	indx[3] = "XL";
	indx[4] = "XXL";
	indx[5] = "XXXL";
	
	cin>>n;
	vector<string> val[n];
	vector<string> ans(n,"-");
	
	for(ll i=0;i<n;i++) {
		cin>>s;
		val[i] = removeDupWord(s);	
	}

	for(ll k=0;k<6;k++) {
		s = indx[k];
		for(ll i=0;i<n;i++) {
			if(val[i].size()==1 && val[i][0]==s) {
				if(size[k]) {
					size[k]--;
					ans[i] = s;
				}
				else {
					cout<<"NO\n";
					return;
				}
			}
		}
		

		for(ll i=0;i<n;i++) {
			if(val[i].size()==2 && val[i][1]==s && ans[i]=="-") {
				if(size[k]) {
					size[k]--;
					ans[i] = s;
				}
				else {
					cout<<"NO\n";
					return;
				}
			}
		}

		for(ll i=0;i<n;i++) {
			if(val[i].size()==2 && val[i][0]==s) {
				if(size[k]) {
					size[k]--;
					ans[i] = s;
				}
			}
		}



		//cout<<indx[k]<<" ";DISP(ans);
	}

	cout<<"YES\n";
	for(ll i=0;i<n;i++) cout<<ans[i]<<"\n";
}

int main() {
	fastio; randomINT;
	//cin >> t;
	while (t--) {
		MAIN();
	}
	return 0;
}