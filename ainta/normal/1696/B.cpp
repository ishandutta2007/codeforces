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

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        int n;
        scanf("%d",&n);
        vi w(n+1);
        rng(i,1,n){
            scanf("%d",&w[i]);
        }
        int b = -1, e = -1;
        rng(i,1,n){
            if(w[i]){
                if(b==-1)b = i;
                e = i;
            }
        }
        int ck=0;
        if(b!=-1){
            rng(i,b,e){
                if(!w[i])ck=1;
            }
        }
        if(ck)printf("2\n");
        else if(b!=-1)printf("1\n");
        else printf("0\n");
    }
}