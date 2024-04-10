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

const int maxn = 1e5+5;

int n,a,b,c;

//int gar(vector<int> ev, vector<int> od, int l0, int r0, int f1, int TAKE) {
//    int took = 0;
//    int at = 0;
//    while (took < TAKE && at < SZ(od)) {
//        ev.pb(od[at++]); took++;
//    }
//    sort(ALL(ev));
//
//}

int t0, t1;

int get(vector<int> vec, int l0, int r0, int f1) {
    // free 0s and free 1s
    sort(ALL(vec));

    for (int x : vec) bug(x);

    bug(f1);

//    multiset<int> ev, od;
//    int duo = l0/2 + r0/2;
//    for(int x : vec) {
//        duo += x/2;
//        if (x % 2 == 0) ev.insert(x);
//        else od.insert(x);
//    }


//    bug(duo);
    int f0 = 0;
    for (int x : vec) f0 += x-1;
    f0 += max(0ll, l0-1);
    f0 += max(0ll, r0-1);

    int b0 = t0 - f0; // bound 0

    // enumerate number of single 0s to take
    int re = 0;

    int tar = f1+1;
    int walk = 0;

    bug(b0, f0, t0);


    for (int ze = 0; ze <= t0; ++ze) {
        // number of possible zero-turns = [ze, ze + duo]
        if (ze) {
            if (b0) {
                --b0; ++f0;
            }
        }
        while (walk < SZ(vec) && walk < ze && tar >= vec[walk]) {
            tar -= vec[walk]; ++walk; ++tar; ++f1;
        }

        bug(ze, walk);

        MX(re, min(f1, f0) * (a + b) - ze * (c+a));
        if (f1 > f0) {
            MX(re, (f0+1)*b + f0 * a - ze * (c+a));
        }
        if (f1 < f0) {
            MX(re, (f1)*b + (f1+1) * a - ze * (c+a));
        }

    }

    return re;
}

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
         cin>>n; // don't forget the special case of no 1s
         cin>>a>>b>>c;
        string s; cin>>s;
        t0=t1=0;
        REP(i,n) {
            if (s[i] == '0') ++t0;
            else ++t1;
        }
        if(*max_element(ALL(s)) == '0') {
            bug("wut");
            if (n == 1) cout<<0<<endl;
            else {
                cout<<a<<endl;
            }
            continue;
        }
        s="0" + s + "0"; // padding
        int cnt = 0;
        vector<int> tmp;
        int n1 = 0;
        REP(i,SZ(s)+1) {
            if (i && (i==SZ(s) || s[i] != s[i-1]) ){
                if (s[i-1] == '0') {
                    tmp.pb(cnt);
                }else{
                    n1 += cnt - 1;
                }
                cnt = 0;
            }
            ++cnt;
        }

        vector<int> prune;
        for (int i = 1; i<SZ(tmp)-1; ++i) prune.pb(tmp[i]);
        tmp[0] --; tmp.back()--;
        int l0 = tmp[0], r0 = tmp.back();

        bug(l0, r0);

        int yo = get(prune, l0,r0,n1);
        cout<<yo<<endl;
    }


}

/*
4
4 100 4 5
0000
5 100 4 5
00000

4 100 100 100
1111
*/