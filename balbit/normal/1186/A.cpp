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
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl  
using namespace std;

// #define int ll

const int maxn = 3e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

ll inv (int b){
	if (b==1) return 1;
	return inv(mod%b) * (mod - mod/b) %mod;
}

ll pow(ll a, ll n, ll mod = 1e9+7){ 
	ll re=1;
	while (n>0){
		if (n&1) re = re*a % mod;
		a = a*a %mod;
		n>>=1;
	}
	return re;
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int a, b, c; cin>>a>>b>>c;
    if (a<=b && a<=c) {
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }

}