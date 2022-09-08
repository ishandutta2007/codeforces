#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
 
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
using ull=unsigned ll;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;



void Solve(){
    int n;
    scanf("%d",&n);
    vi w(n);
    int Mx = -1e9;
    int Mn = 1e9;
    rep(i,n){
        scanf("%d",&w[i]);
        Mx = max(Mx, w[i]);
        Mn = min(Mn, w[i]);
    }
    int res = 0;
    rep(i,n){
        res = max(res, w[i] - w[(i+1)%n]);
    }
    printf("%d\n",max({res, w[n-1] - Mn, Mx - w[0]}));

}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}