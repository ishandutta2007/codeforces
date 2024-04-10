#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
	ll re=1;
	while (n>0){
		if (n&1) re = re*a %mod;
		a = a*a %mod;
		n>>=1;
	}
	return re;
}

ll inv (ll b){
	if (b==1) return b;
	return (mod-mod/b) * inv(mod%b) % mod;
}

string odd(string s){
	int n = s.length();
	int m = (n-1)/2;
	string b = s; reverse(ALL(b));
	string re = "";
	for (int i = 0; i+1<m; i+=2){
		if (b[i]==s[i]) re+=b[i];
		else if (b[i]==s[i+1]) re+=b[i];
		else re+=b[i+1];
	}
	string re2 = re; reverse(ALL(re2));
	return re+s[m]+re2;
}

string even(string s){
	int n = s.length();
	int m = (n-1)/2;
	string b = s; reverse(ALL(b));
	string re = "";
	for (int i = 0; i+1<=m; i+=2){
		if (b[i]==s[i]) re+=b[i];
		else if (b[i]==s[i+1]) re+=b[i];
		else re+=b[i+1];
	}
	string re2 = re; reverse(ALL(re2));
	return re+re2;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s; cin>>s;
  	int n = s.length();
  	// debug(n);
  	if (n<4){
  		cout<<s[0]<<endl; return 0;
  	}
  	if (n%4==2){
  		// cout<<"HI"<<endl;
  		s.pop_back();
  		cout<<odd(s)<<endl; return 0;
  	}
  	if (n&1){
  		cout<<odd(s)<<endl;
  	}else{
  		cout<<even(s)<<endl;
  	}

    
}