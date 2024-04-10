#include <bits/stdc++.h>
 #pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
 
// #define int ll
 
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
 
const int maxn = 5e5+5;
#define poo pair<pii, int>
vector<poo > que;
int BS = 500;
int ans[maxn], a[maxn];
ll ord[maxn];
 
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
bool cmp(poo a, poo b){
    return ord[a.s] < ord[b.s];
}
 
int app[maxn];
queue<int> pos;
bool iq[maxn];
 
void add(int x){
    app[a[x]]++; if (app[a[x]]==1 && !iq[a[x]]) pos.push(a[x]), iq[a[x]]=1;
}
 
void del(int x){
    app[a[x]]--; if (app[a[x]]==1 && !iq[a[x]]) pos.push(a[x]), iq[a[x]]=1;
}
 
int getans(){
    while (pos.size()){
        if (app[pos.front()]==1) return pos.front();
        iq[pos.front()]=0;
        pos.pop();
    }
    return 0;
}
 
main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    REP(i,n) cin>>a[i];
    int q; cin>>q;
    BS = n/(sqrt(q)) + 3;
    REP(i, q){
        int l, r; cin>>l>>r; 
        que.pb({{l-1,r-1},i});
        ord[i] = gilbertOrder(l,r,21,0);
    }
    sort(ALL(que), cmp);
    int nl=0, nr = -1;
    REP(i, SZ(que)){
        int l = que[i].f.f, r = que[i].f.s;
        while (nl>l){
            nl--; add(nl);
        }
        while (nr<r){
            nr++; add(nr);
        }
        while (nl<l){
            del(nl); nl++;
        }
        while (nr>r){
            del(nr); nr--;
        }
        ans[que[i].s] = getans();
    }
    REP(i,q){
        cout<<ans[i]<<'\n';
    }
}