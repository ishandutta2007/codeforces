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

const int maxn = 1e6+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 998244353;


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

bool prime[maxn];

void build(){
	fill(prime, prime+maxn, 1);
	prime[0]=prime[1]=0;
	FOR(i,2,maxn) {
		if (!prime[i]) continue;
		for (int j = i+i; j<maxn; j+=i){
			prime[j]=0;
		}
	}
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    build();
    int n; cin>>n;
    vector<pii> pp;
    REP(i,n){

    	pp.pb({i+1,(i+1)%n+1});
    }
    int np = n;
    REP(i,n/2){
    	if (prime[np]){
    		break;
    	}
    	pp.pb({i+1,i+n/2+1});
    	np++;
    }
    cout<<pp.size()<<endl;
    for (pii xx : pp){
    	cout<<xx.f<<' '<<xx.s<<'\n';
    }
    
}