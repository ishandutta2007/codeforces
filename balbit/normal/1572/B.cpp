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

vector<int> clr(vector<int> x) {
    assert(x[0] == 0);
    int sg = 0; for(int y : x) sg += y;
    assert(sg % 2 == 0);
    vector<int> re;
    for (int i = 1; i<SZ(x); ++i) {
        if (x[i] == 1) {
            if (x[i+1] == 1) {
                re.pb(i);
                x[i] = x[i+1] = 0;
            }else{
                if (x[i+2] == 1) {
                    re.pb(i+1);
                    x[i] = x[i+2] = 0;
                }else{
                    re.pb(i+1);
                    re.pb(i);
                    x[i] = 0;
                    x[i+2] = 1;
                }
            }
        }
    }
    return re;
}


signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        int OX =0;
        REP(i,n) cin>>a[i], OX ^= a[i];
        if (OX != 0) {
            cout<<"NO"<<endl;
            continue;
        }

        int cnt1 = 0;
        int l = -1, r = -1;
        REP(i,n) {
            if (a[i] == 0) {
                if (cnt1 %2 == 0) {
                    l = r = i; break;
                }
            }else{
                ++cnt1;
            }
        }

        vector<int> re;

        if (l == -1) {
            int prv1 = -1;
            REP(i,n) {
                if (a[i] == 1) {
                    if ((i - prv1) % 2 == 0) {
                        l = prv1; r = i; break;
                    }

                    prv1 = i;
                }
            }
            bug(l,r);
            if (l !=-1) {
                // commence weird sequence to remove this section
                int j = l;
                for (; j<r; j+=2) {
                    re.pb(j);
                }
                j-=4;
                for (; j>=l; j-=2) {
                    re.pb(j);
                }
            a[l] = a[r] = 0;
            }
        }

        if (l == -1) {
            cout<<"NO"<<endl; continue;
        }
        {
            vector<int> go;
            for (int i = l; i>=0; --i) go.pb(a[i]);
            vector<int> yep = clr(go);
            for (int &x : yep) {
                re.pb(l-x-1);
            }
        }
        {
            vector<int> go;
            for (int i = r; i<n; ++i) go.pb(a[i]);
            vector<int> yep = clr(go);
            for (int &x : yep) {
                re.pb(r+x-1);
            }
        }
        cout<<"YES\n"<<SZ(re)<<endl;
        for (int y : re) {
            cout<<y+1<<' ';
        }
        cout<<endl;
    }


}