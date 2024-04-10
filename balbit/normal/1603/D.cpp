#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e5+5;


ll cnt[maxn], phi[maxn], np[maxn];
ll ans[18][maxn];

ll cal(int l, int r) {
    // calculate from l to r
    int at = r;
    ll re = 0;
    while (at >= l) {
        int now = r/at;
        int lb = 1+(r)/(now+1); // floor(r/nxt) = now+1
        if (lb < l) lb = l;
        re += cnt[now] * (at - lb + 1);
        at = lb-1;
    }
    return re;
}

void dnc(int K, int l, int r, int ql, int qr) {
    if (l > r) return;
    int mid = (l+r)/2;
    int mopt = -1;
    ll bst = inf;
    int stp = qr; if (stp > mid) stp = mid;
    ll toqr = cal(stp, mid);
    for (int q = stp; q>=ql; --q) {
        if (q != stp) {
            toqr += cnt[mid/q];
        }
        ll tmp = toqr + (q==0?0:ans[K-1][q-1]);
        if (tmp < bst) {
            bst = tmp;
            mopt = q;
        }
    }
    ans[K][mid] = bst;
    if (l!=r) {
        dnc(K, l,mid-1,ql,mopt);
        dnc(K,mid+1,r,mopt,qr);
    }
}

signed main(){
    IOS();
    for (int i = 1; i<maxn; ++i) phi[i] = i;
    np[0] = np[1] = 1;
    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) for (int j = i; j<maxn; j+=i) {
            phi[j] = phi[j] / i * (i-1);
            if (j != i) np[j] = 1;
        }
    }
//    REP1(i,10) bug(i, phi[i]);
    for (int i = 1; i<maxn; ++i) {
        cnt[i] = phi[i] + cnt[i-1];
    }

    bug(cal(3,6));
    bug(cal(1,2));

    for (int i = 1; i<maxn; ++i) {
        ans[0][i] = cal(1,i);
    }

    for (int j = 1; j<18; ++j) {
        dnc(j, 1,maxn-1,1, maxn-1);
    }

    int t; cin>>t;
    while (t--) {
        int a,b; cin>>a>>b;
        if (b > 17) cout<<a<<endl;
        else cout<<ans[b-1][a]<<endl;
    }

}