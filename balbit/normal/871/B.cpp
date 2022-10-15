#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

#ifdef Balb
#define bug(x) cerr<<#x<<" is "<<x<<endl
#else
#define bug(x)
#endif
using namespace std;

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

vector<int> psb(maxn+1);
int f(int l, int r){
    if (l>r) swap(l,r);
    return psb[l]^psb[r];
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<int> self(n), nxt(n);
    REP(i,n) {
        cout<<"? "<<i<<' '<<i<<endl; cin>>self[i];
    }
    REP(i,n){
        cout<<"? "<<i<<' '<<(i+1)%n<<endl; cin>>nxt[i];
    }
    vector<int> adjb(n);
    
    REP(i,n){
        adjb[i] = self[i] ^ nxt[i];
        psb[i+1] = psb[i] ^ adjb[i];
    }
    cout<<"!\n";
    bool prt = 0;
    int nat = 0;
    vector<int> tprint;
    REP(st,n){
        // b[st] = 0
        bug(st);
        vector<int> b(n,-1);
        vector<int> p(n);
        REP(i,n){
            b[i] = f(i,st);
            p[i] = self[i] ^ b[i];
        }
        bool fg = 1;
        for (int i = 0; i<n; i++){
            if (b[p[i]]!=i) {fg=0; break;}
        }
        if (!fg) continue;
        if(!prt){
            tprint = p;
        }
        nat  ++;
    }
    cout<<nat<<'\n';
    for (int x : tprint) cout<<x<<' ';
    
}