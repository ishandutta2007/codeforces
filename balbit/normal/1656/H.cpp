#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
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

const int maxn = 1e3+5;


#define LL __int128


struct Tree{
    LL s[maxn*4];
    LL val; // value that they are taking gcd with
    void build(int o, int l, int r, LL *a) {
        if (l == r) {
            s[o] = val / __gcd((LL)a[l], val); // s[o] stores the factors needed to complete val's factors
            return;
        }
        int mid = (l+r)/2;
        build(o*2, l, mid, a); build(o*2+1, mid+1, r, a);
        s[o] = __gcd(s[o*2], s[o*2+1]);
    }
    void MO(int p, int o, int l, int r) {
        if (l == r) {
            s[o] = val; return;
        }
        int mid = (l+r)/2;
        if (p <= mid) MO(p,o*2,l,mid);
        else MO(p, o*2+1, mid+1, r);
        s[o] = __gcd(s[o*2], s[o*2+1]);
    }
};

Tree TA[maxn], TB[maxn];
LL a[maxn], b[maxn];
bool deada[maxn], deadb[maxn];

void IN(LL &x) {
    string s; cin>>s;
    x=0;
    for (char c : s) {
        x = x * 10 + c - '0';
    }
}

void OUT(LL &x) {
    string ra;
    while(x) {
        ra.pb(('0' + x%10)); x/=10;
    }
    reverse(ALL(ra)) ;cout<<ra<<' ';
}

signed main(){
    IOS();

    int T; cin>>T;
    while (T--) {
        int n,m; cin>>n>>m;
        memset(deada, 0, sizeof deada);
        memset(deadb, 0, sizeof deadb);
        REP(i,n) {
            IN(a[i]); TA[i].val = a[i];
        }
        REP(i,m) {
            IN(b[i]); TB[i].val = b[i];
        }
        queue<pii> rm; // {0:A 1:B, position}
        REP(i,n) {
            TA[i].build(1,0,m-1,b);
            if (TA[i].s[1] != 1) {
                rm.push({0, i});
                deada[i] = 1;
            }
        }
        REP(i,m) {
            TB[i].build(1,0,n-1,a);
            if (TB[i].s[1] != 1) {
                rm.push({1,i});
                deadb[i] = 1;
            }
        }

        while (!rm.empty()) {
            int who = rm.front().f, i = rm.front().s;
            bug(who, i);
            rm.pop();
            if (who == 0) {
                // kill that position in 1
                REP(e, m) {
                    if (!deadb[e]) {
                        TB[e].MO(i, 1, 0, n-1);
                        if (TB[e].s[1] != 1) {
                            rm.push({1,e});
                            deadb[e] = 1;
                        }
                    }
                }
            }else{
                REP(e, n) {
                    if (!deada[e]) {
                        TA[e].MO(i, 1, 0, m-1);
                        if (TA[e].s[1] != 1) {
                            rm.push({0,e});
                            deada[e] = 1;
                        }
                    }
                }
            }
        }

        vector<int> oka, okb;
        REP(i,n) if (!deada[i]) oka.pb(i);
        REP(i,m) if (!deadb[i]) okb.pb(i);

        if (SZ(oka) == 0 || SZ(okb) == 0) {
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<SZ(oka)<<' '<<SZ(okb)<<endl;
            for (int x : oka) OUT(a[x]);
            cout<<endl;
            for (int x : okb) OUT(b[x]);
            cout<<endl;
        }
    }

}