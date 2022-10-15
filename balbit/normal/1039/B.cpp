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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

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

const int maxn = 1e5+5;



main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    ll n; ll k; cin>>n>>k;
    ll l = 1, r = n;
    int nq = 0;
    while(1){
        ll mid = (l+r)/2;
        ll c1 = min(n, r+k) - max(1ll,mid+1-k) + 1;
        ll c2 = min(n, mid+k) - max(1ll,l-k) + 1;
        if (max(c1, c2) >= r-l+1){
            ll at = (rng()%(r-l+1)) + l;
            cout<<at<<' '<<at<<endl; nq++;
            string res; cin>>res; 
            if (res=="YES") {assert(0);}
            
        }else{
            cout<<l<<' '<<mid<<endl; nq++;
            string res; cin>>res;
            if (res[0]=='Y'){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        l-=k; r+=k; MXTO(l,1); MNTO(r,n);
        if (nq>4000) {cout<<"BOB"<<endl; return 0;}
    }
    
}