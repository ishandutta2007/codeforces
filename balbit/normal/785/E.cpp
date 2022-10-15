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

const int maxn = 2e5+5;
const int KKK = 3;

struct BIT{
    vector<int> s;
    int MX=0;
    int QU(int e) {
        ll re = 0; e++;
        while (e>0){
            re += s[e]; e-=e&(-e);
        }return re;
    }
    int QQ(int l){
        return QU(MX-1) - QU(l);
    }
    void MO(int e, int v){
        e++; 
        while (e<MX){
            s[e]+=v;
            e+=e&(-e);
        }
    }
    void setsz(int msz) {
        MX = msz; s.resize(MX+1);
    }
};

int BS; 
int id(int x){
    return x / BS;
}
vector<BIT> bb;
int a[maxn];

int mor(int l, int r, int grt){
    if (l>r) return 0;
    // int b1 = id(l), b2 = id(r);
    int re = 0;
    while (l<r+1 && l%BS !=0){
        re += a[l] > grt;
        l++;
    }
    while (l+BS<r+1){
        re+=bb[id(l)].QQ(grt);
        l+=BS;
    }
    while (l<r+1){
        re += a[l]>grt;
        l++;
    }
    return re;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    BS = sqrt(n * log2(n+1) * 3);
    bb.resize(n/BS+1);
    REP(i,SZ(bb)){
        bb[i].setsz(n+2);
    }
    FOR(i,0,n){
        a[i] = i;
        bb[id(i)].MO(i,1);
    }
    
    ll fst = 0;
    // int q; cin>>q;
    while (q--){
        int l, r; cin>>l>>r;
        l--; r--;
        if (l>r) swap(l,r);
        if (l==r) {
            cout<<fst<<'\n'; continue;
        }
        int mdf = (mor(l+1,r-1, a[l]) - mor(l+1, r-1, a[r])) * 2;
        // debug(mdf);
        if (a[l] > a[r]) mdf-=1;
        else mdf+=1;
        fst += mdf; 
        cout<<fst<<'\n';
        bb[id(l)].MO(a[l], -1); bb[id(l)].MO(a[r], 1); 
        bb[id(r)].MO(a[l], 1); bb[id(r)].MO(a[r], -1); 
        swap(a[l], a[r]);
    }
    
}