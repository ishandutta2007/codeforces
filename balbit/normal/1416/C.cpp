#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

const int maxn = 30 * 200000+5;
using namespace __gnu_pbds;
//gp_hash_table<signed, int> mp[31];
int wei[31];



//int s[maxn];
//
//ll QU(int e) {
//    ll re = 0;
//    for (++e; e>0; e-=e&-e) re += s[e];
//    return re;
//}
//
//void MO(int e, int v) {
//    for (++e; e<maxn; e+=e&-e) s[e] += v;
//}


int NOW = 0;
int to[maxn][2];
int nof[maxn];

signed main(){
    IOS();
    int n; cin>>n;
    memset(to, -1, sizeof to);
//    map<int, int> mp;
    vector<int> A(n);
    int org = 0;
    for (int i = 0; i<n; ++i) {
        signed a; cin>>a; A[i] = a;
        int now = 0;
        int at = 0;
        for (int j = 29; j>=0; --j) {
            now += a & (1<<j);
            bool dir = (a>>j) & 1;
            if (to[at][dir^1] != -1) {
                int tmp = nof[to[at][dir^1]];
                wei[j] += (dir?1:-1) * tmp;
                if (!dir) org += tmp;
            }
            if (to[at][dir] == -1) {
                to[at][dir] = ++NOW;
            }
            nof[to[at][dir]] ++;
            at = to[at][dir];
//            if (mp[j].count(tmp ^ (1<<(j-1)))) {
//                int nm2= mp[j][tmp ^ (1<<(j-1))];
//            }
//            mp[j][tmp ^ (1<<(j-1))] ++;
        }
    }
    bug(org);
    int X = 0;
    int re =0;
    for (int j = 29; j>=0; --j) {
        if (wei[j] < 0) X += (1<<j);
        bug(j, wei[j]);
//        re += abs(wei[j]);
        re += min(wei[j], 0ll);
    }
    bug(re);
    bug(X);
    cout<<org+re<<' ';
//    for (int x : )
//cout<<(n) * (n-1) / 2 - 2*re<<endl;
    cout<<X<<endl;

}