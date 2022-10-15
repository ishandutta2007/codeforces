#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
// #define prt(...)
#endif

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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

const int maxn = 1e5+5;

vector<int> sum(vector<int> a, vector<int> &b){
    if (SZ(a)!=SZ(b)) assert(0);
    REP(i, SZ(b)) a[i] += b[i]; return a;
}

int chg[(1<<15)][105];
int chg2[1<<15][105];

void prt(vector<int> a){
    for (int x : a) cerr<<x<<' ';
    cout<<endl;
}

main(){
    IOS();
    int n; cin>>n; int n2 = 30/2;
    vector<int> arr(n);
    vector<int> at[maxn];
    vector<int> ori;
    int mnori = iinf;
    REP(i,n) {
        cin>>arr[i];
        ori.pb(-__builtin_popcount(arr[i]));
        MN(mnori, ori.back());
        REP(j,n2){
            if (arr[i] & (1<<j)) {
                chg[1<<j][i] = -1;
            }
            else {
                chg[1<<j][i] = 1;
            }
            // cout<<chg[1<<j][i]<<' ';
        }
        // cout<<endl;  
        FOR(j,n2,30){
            if (arr[i] & (1<<j)) {
                chg2[1<<(j-n2)][i] = -1;
            }
            else {
                chg2[1<<(j-n2)][i] = 1;
            }
        }
    }

    map<vector<int>, int> msk;
    
    REP(mat,1<<n2){
        vector<int> moe(n,0);
        if (__builtin_popcount(mat) > 1){
            int lb = mat & (-mat);
            REP(k,n) chg[mat][k] = chg[mat-lb][k] + chg[lb][k], moe[k]+=chg[mat][k];
            
        }else if (__builtin_popcount(mat) == 1){
            REP(k,n) moe[k] = chg[mat][k];
        }
        // if (mat < (1<<4)){
        //     bug(mat); prt(moe);
        // }
        msk[moe] = mat;
    }
    int N2 = 30-n2;
    REP(mat,1<<(N2)){
        vector<int> moe = ori;
        if (__builtin_popcount(mat) > 1){
            int lb = mat & (-mat);
            
            REP(k,n) chg2[mat][k] = chg2[mat-lb][k] + chg2[lb][k], moe[k] -= chg2[mat][k];
            
        }else if (__builtin_popcount(mat) == 1){
            REP(k,n) moe[k] -= chg2[mat][k];
        }
        REP(tk, 30){ // try-k
            if (msk.count(moe)) {
                // bug("ANS");
                // prt(ori);
                // prt(moe);
                // bug(mat, tk);
                cout<<(mat<<n2) + msk[moe] <<endl; return 0;
            }
            for (int & x : moe) x ++ ;
        }
    }
    cout<<-1<<endl;
}