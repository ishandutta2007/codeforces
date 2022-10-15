#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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


void GG(){cout<<"IMPOSSIBLE\n"; exit(0);}

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

const int maxn = 2e5+5;

ll a[maxn], b[maxn];
int n;

pair<int, vector<int> > gt(){
        vector<int> dir;
        int stp = 0;
        for ( stp = 0; ; ++stp) {
            // check for equality
            bool ie = 1;
            for (int j = 0; j<n; ++j) {
                if (a[j] != b[j]) {
                    ie = 0; break;
                }
            }
            if (ie) break;
    //        if (ie) {
    //            done = 1; break;
    //        }
            if (stp > 200000 && n == 2) {
                int x = 0, y = 1; if (b[x] > b[y]) swap(x,y);
                int gp = (b[y] - a[y]) / (b[x]);
                if (gp <= 0) return {100000000000000000ll, {} };
                b[y] -= b[x] * gp;
                stp += gp-1;
                continue;
            }
            dir.pb(b[0]<b[n-1]);
            if (!dir.back()) {
                for (int j = 0; j<n; ++j) {
                    b[j] -= b[j+1];
                    if (b[j] < a[j]) return {100000000000000000ll, {} };
                }
            }else{
                for (int j = n-1; j>=0; --j) {
                    if (j)
                        b[j] -= b[j-1];
                    if (b[j] < a[j]) return {100000000000000000ll, {} };
                }
            }
    //        for (int i = 0 ;i<n; ++i) {
    //            cout<<b[i]<<' ';
    //        }
    //        cout<<endl;
        }
    return {stp, dir};
}

int c[maxn];

signed main(){
    IOS();
    cin>>n;

    for (int i = 0 ;i<n; ++i) cin>>a[i];
    for (int i = 0; i<n; ++i) cin>>b[i], c[i] = b[i];

    if (n == 1) {
        if (a[0] != b[0]) GG();
        else cout<<"SMALL\n0\n";
        return 0;
    }
    pair<pair<int, vector<int> >, bool> hi = {gt(),0};
    for (int i = 0; i<n; ++i) b[i] = c[n-i-1];
    hi = min(hi, {gt(),1});
    int stp = hi.f.f;
    vector<int> dir = hi.f.s;
    if (hi.f.f == 100000000000000000ll) GG();
    if (stp <= 200000) {
        cout<<"SMALL"<<endl;
        reverse(ALL(dir));
        bool now = 1;
        string s="";
        for (int x : dir) {
            if (x != now) {
                s.pb('R');
            }
            s.pb('P');
            now = x;
        }
        if (now == hi.s) s.pb('R');

        cout<<SZ(s)<<endl<<s<<endl;
    }else{
        cout<<"BIG"<<endl;
        cout<<stp<<endl;
    }
}