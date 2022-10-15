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
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

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

const int maxn = 4e5+5;

struct Que{
    ll t;
    ll l, r; 
};

map<ll, int> mp;

int s[maxn<<2], tg[maxn<<2];

void push(int o, int l, int r){
    if (!tg[o]) return;
    if (tg[o]&1){
        s[o] = (r-l+1);
    }
    if (tg[o]&2){
        s[o] = 0;
    }
    if (tg[o]&4){
        s[o] = (r-l+1-s[o]);
    }
    if (l!=r){
        if (tg[o]==4){
            if (tg[o*2+1]==0) tg[o*2+1] = 4;
            else if (tg[o*2+1]==1) tg[o*2+1] = 2;
            else if (tg[o*2+1]==2) tg[o*2+1] = 1;
            else if (tg[o*2+1]==4) tg[o*2+1] = 0;
            if (tg[o*2]==0) tg[o*2] = 4;
            else if (tg[o*2]==1) tg[o*2] = 2;
            else if (tg[o*2]==2) tg[o*2] = 1;
            else if (tg[o*2]==4) tg[o*2] = 0;
        }else {
            tg[o*2+1] = tg[o*2] = tg[o];
        }
    }
    tg[o]=0;
}

int MEX(int o, int l, int r){
    if (l==r) return l;
    int mid = l+r>>1;
    push(o,l,r);
    push(o*2,l,mid);
    if (s[o*2]!=(mid-l+1)) {
        return MEX(o*2,l,mid);
    }else{
        return MEX(o*2+1,mid+1,r);
    }
}

int L, R, T;

void MO(int o, int l, int r){
    push(o,l,r);
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        tg[o] |= T; push(o,l,r); return;
    }
    int mid = l+r>>1;
    MO(o*2,l,mid); MO(o*2+1,mid+1,r);
    s[o] = s[o*2] + s[o*2+1];
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<Que> q;
    vector<ll> hv = {0};
    REP(i,n){
        ll t,l,r; cin>>t>>l>>r; if (t==3) t++; l--; r--;     
        q.pb({t,l,r}); 
        hv.pb(l); hv.pb(r); hv.pb(l+1); hv.pb(r+1);
    }
    SORT_UNIQUE(hv);
    REP(i,SZ(hv)){
        mp[hv[i]] = i;
    }
    for (auto &x : q){
        L = mp[x.l]; R = mp[x.r]; T = x.t;
        MO(1,0,maxn-1);
        cout<<hv[MEX(1,0,maxn-1)]+1<<'\n';
    }

    
}