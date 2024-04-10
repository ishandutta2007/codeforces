#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
#define ll long long
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

const int maxn = 1e6+5;

bool hv[10000004];
bool V[10000004];
vector<int> mo[10000004];
int mn[10000004];

signed main(){
    IOS();
    memset(mn, 0x3f, sizeof mn);

    int n;
    #ifndef BALBIT
    cin>>n;
    #else
    n = 1000000;
    #endif
    vector<int> v;
    for (int i = 0; i<n; ++i) {
            int x;
        #ifdef BALBIT
        x = 10000000-i;
        #else
        cin>>x;
        #endif // BALBIT
        v.pb(x);
        V[x] = 1;
    }
    clock_t t = clock();
    vector<int> E = v;
    sort(ALL(v));
    ll re = v[0] * (ll)v[1];
    vector<int> a;
    for (int i = 0; i<n; ++i) {
        if (v[i] == v[i-1]) {
            re = min(re, (ll)v[i]);
        }else{
            if (!hv[v[i]]) {
                a.pb(v[i]);
                mo[v[i]].reserve(100);
                for (int j = v[i]; j < 10000004; j += v[i]) hv[j] = 1;
            }else{
                re = min(re, (ll)v[i]);
            }
        }
    }
    bug((clock() - t) / (double) CLOCKS_PER_SEC);
    t = clock();
    int td = 0;
    for (int j = 2; j<10000004/6; ++j) {
        if (td > 10000000) break;
        for (int i = j+j; i<10000004; i += j) {
            if (V[i]) {
                td++;
                mo[i].emplace_back(j);
            }
        }
    }
    bug(td);
    bug((clock() - t) / (double) CLOCKS_PER_SEC);
    t = clock();
    for (int x : a) {
        for (int y : mo[x]) {
//            bug(x,y);
            if (mn[y] != 0x3f3f3f3f) {
                re = min(re, x / y * (ll)mn[y]);
            }
            mn[y] = min(mn[y], x);
        }
    }
    bug((clock() - t) / (double) CLOCKS_PER_SEC);
    t = clock();
    int moe = 2;
    for (int i = 0; moe != 0; ++i) {
        if (re % E[i] == 0) {
            #ifndef BALBIT
            cout<<i+1<<' ';
            #endif
            moe--;
        }
    }
    bug((clock() - t) / (double) CLOCKS_PER_SEC);
    t = clock();
}