#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//#define int ll
 
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

ll rand_int(ll l, ll r) { //[l, r]
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}

#define N_ 251000

int w[N_], L1[N_], R1[N_], L2[N_], R2[N_], st[N_], D[N_], INF = 1e9;
struct Tree{
    int IT[1<<20], SZ;
    void init(int n){
        SZ = 1;
        while(SZ<=n)SZ*=2;
        rep(i,SZ+SZ)IT[i]=INF;
    }
    void Put(int a, int b){
        a+=SZ;
        IT[a]=b;
        while(a!=1){
            a>>=1;
            IT[a]=min(IT[a*2],IT[a*2+1]);
        }
    }
    int Get(int b, int e){
        b+=SZ,e+=SZ;
        int r = INF;
        while(b<=e){
            r=min(r,min(IT[b],IT[e]));
            b=(b+1)>>1,e=(e-1)>>1;
        }
        return r;
    }
}T1, T2;

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        int n;
        scanf("%d",&n);
        rng(i,1,n){
            scanf("%d",&w[i]);
        }
        int top=0;
        rng(i,1,n){
            L1[i]=L2[i]=1, R1[i]=R2[i]=n;
        }
        rng(i,1,n){
            while(top && w[st[top]] < w[i]){
                R1[st[top]] = i-1;
                top--;
            }
            L1[i] = st[top]+1;
            st[++top] = i;
        }
        top = 0;
        rng(i,1,n){
            while(top && w[st[top]] > w[i]){
                R2[st[top]] = i-1;
                top--;
            }
            L2[i] = st[top]+1;
            st[++top] = i;
        }
        rng(i,1,n){
            //printf("%d %d %d %d\n",L1[i],R1[i],L2[i],R2[i]);
            D[i]=1e9;
        }
        T1.init(n);
        T2.init(n);
        vc<vi>G1(n+1), G2(n+1);
        rng(i,1,n){
            G1[R1[i]].pb(i);
            G2[R2[i]].pb(i);
        }
        D[1]=0;
        rng(i,2,n){
            T1.Put(i-1,D[i-1]);
            T2.Put(i-1,D[i-1]);
            for(auto &x : G1[i-1]){
                //printf("! %d\n",x);
                T1.Put(x, INF);
            }
            for(auto &x : G2[i-1]){
                //printf("? %d\n",x);
                T2.Put(x, INF);
            }
            //printf("%d\n",L1[i]);
            int d1 = T1.Get(L2[i], i-1) + 1;
            int d2 = T2.Get(L1[i], i-1) + 1;
            D[i] = min(d1,d2);
        }
        printf("%d\n",D[n]);
    }
}