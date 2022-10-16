#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define in(x) (read(x))
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define _sort(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9+7;
const ld eps = 1e-9;
const int inf = mod;
template<typename T>
inline int sign(const T&a){if(a<0)return -1;if(a>0)return 1;return 0;}



template<typename T> inline void read(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

const int maxn = 100010;
ll ssum[maxn];
ll sum[maxn];


int main(){
    int n;in(n);
    REP(i,1,n+1){
        in(sum[i]);ssum[i] = sum[i];
    }
    sort(ssum+1,ssum+1+n);
    REP(i,1,n+1){
        sum[i]+=sum[i-1];
        ssum[i]+=ssum[i-1];
    }
    int q;in(q);
    while(q--){
        int t,l,r;in(t);in(l);in(r);
        if(t == 1){
            lout(sum[r]-sum[l-1]);
        }else{
            lout(ssum[r]-ssum[l-1]);
        }
    }
    return 0;
}