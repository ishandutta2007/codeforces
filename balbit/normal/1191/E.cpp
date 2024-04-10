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

ll pow(ll a, ll n){ // a^n % mod
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

int n, k; 

bool one(string s){
	for (char ch = '0'; ch<='1'; ch++){
		int f1= iinf, f2=-1;
		REP(i, n){
			if (s[i]==ch) {
				f1 = i; break;
			}
		}
		RREP(i, n){
			if (s[i]==ch) {
				f2 = i; break;
			}
		}
		if (f2-f1+1<=k) return true;
	}
	return 0;
}

bool two(string s){
	vector<int> at[2];
	for (char ch = '0'; ch<='1'; ch++){
		REP(i,n){
			if (s[i]==ch){
				at[ch-'0'].pb(i);
			}
		}
	}
	REP(i,n-k+1){
		// From i to i+k-1
		for (char ch = '0'; ch <= '1'; ch++){
			// Switching this section to ch
			// Test to see of second player can change the rest to ch
			// Second player cannot switch to ch^1 because it would have to reverse 1st player's move
			int x = ch-'0';
			int lx, rx; // Leftmost appearance of x^1
			if (i > at[x^1][0]){
				lx = at[x^1][0];
			}else{
				lx = *upper_bound (ALL(at[x^1]), i+k-1);
			}
			if (i+k-1 < at[x^1].back()){
				rx = at[x^1].back();
			}else{
				rx = *prev(lower_bound (ALL(at[x^1]), i));
			}
			if (rx-lx+1>k){ // Doesn't work for player 2
				return 0;
			}
		}

	}
	return 1;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    string s; cin>>s;
    string FIRST = "tokitsukaze", SECOND = "quailty";
    if (one(s)){
    	cout<<FIRST<<endl; return 0;
    }
    if (two(s)) {
    	cout<<SECOND<<endl; return 0;
    }
    else {
    	cout<<"once again"<<endl; return 0;
    }

    
}