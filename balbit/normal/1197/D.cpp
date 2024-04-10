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

const int maxn = 3e5+5;
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

ll a[maxn];

ll s[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, k; cin>>n>>m>>k;
    // cin>>n>>m>>k;
    REP(i,n) cin>>a[i];
    ll re = 0;
    // debug(m);
    REP(md,m){
        int tg = (md+1+m)%m;
        fill(s, s+n+1,0);
        // fill(frm, frm+n+1, -1);
        REP(i,n){
            s[i]=a[i]; 
            if (i%m==md) s[i]-=k;
            // frm[i]=i;
            if (i && s[i-1]>0) {
                s[i]+=s[i-1];
                // frm[i]=frm[i-1];
            }
            // cout<<"Tried";
            if (i%m==md){
                // cout<<"UPD"<<endl;
                MXTO(re, s[i]);
            }
        }
    }
    cout<<re<<'\n';

    
}