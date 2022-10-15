#include <bits/stdc++.h>
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
//#define endl '\n'
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

int tt = 0;
//vector<vector<int> > tb = {4,1,2}, {}
int tb[5][5];
int n,m;
int C(int a, int b) {
    tt++;
//    a = n-a+1;
//    b = m-b+1;
    bug(a,b);
#ifndef BALBIT
cout<<"? "<<a<<' '<<b<<endl;
    int x; cin>>x; return x;
#endif // BALBIT
    return tb[a-1][b-1];
}

int RE = 1000000000;


vector<int> smawk(vector<int> row, vector<int> col){
    if (SZ(col) <= 4) {
        vector<int> ret;
        for (int i = 0; i<SZ(row); ++i){
            int mybest = 1e9+2;
            ret.pb(0);
            for (int j = 0; j<SZ(col); ++j) {
                ll cc = C(row[i], col[j]);
                if (cc < mybest) {
                    ret.back() = col[j];
                    mybest = cc;
                }
            }
            RE=min(RE,mybest);
        }
        return ret;
    }
    if (SZ(col) > SZ(row)) {
        vector<int> nc;
        for (ll cc : col) {
            while (true) {
                if (nc.size() == 0) break;
                ll rr = row[nc.size() - 1];
                if (C(rr, cc) > C(rr, nc.back()))
                    break;
                nc.pop_back();
            }
            if (nc.size() < row.size())
                nc.push_back(cc);
        }
        return smawk(row, nc);
    }else{
        vector<int> odds;
        for (int i = 1; i<SZ(row); i += 2) {
            odds.pb(row[i]);
        }
        vector<int> pos = smawk(odds, col);
        pos.pb(col.back());
        vector<int> ret;
        int j = 0;
        for (int i = 0; i<SZ(row); i++) {
            if (i & 1) {
                ret.pb(pos[i/2]);
            }else{
                ret.pb(col[j]);
                int mybest = 1e9+2;
                for (int k = j; k < SZ(col) && col[k] >= pos[i/2]; ++k) {
                    ll cc = C(row[i], col[k]);
                    if (cc < mybest) {
                        mybest = cc; ret.back() = col[k];
                    }
                    j=k;
                }
                RE = min(RE, mybest);
            }
        }
        return ret;
    }

}


signed main(){

    IOS();
    cin>>n>>m;
#ifdef BALBIT
    for (int i = 0; i<n; ++i) for (int j = 0 ;j <m; ++j) {
        cin>>tb[i][j];
    }
#endif
    vector<int > nn(n), mm(m);
    for (int i = 0; i<n; ++i) {
        nn[i] = i+1;
    }
    for (int i = 0; i<m; ++i) {
        mm[i] = i+1;
    }
    reverse(ALL(nn));
    reverse(ALL(mm));
    vector<int> rr = smawk(nn, mm);
    bug(tt);
    cout<<"! "<<RE<<endl;
}