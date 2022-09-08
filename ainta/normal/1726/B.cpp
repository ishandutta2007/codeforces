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
    int n, m;
    scanf("%d%d",&n,&m);
    if(n>m){
        puts("No");
        return;
    }
    if(n%2==0 && m%2==1){
        puts("No");
        return;
    }
    if(n%2==1){
        puts("Yes");
        vi w;
        rng(i,1,n-1)w.pb(1);
        w.pb(m-(n-1));
        for(auto &t : w)printf("%d ",t);
        puts("");
        return;
    }
    puts("Yes");
    vi w;
    rng(i,1,n-2)w.pb(1);
    int t = (m-(n-2)) / 2;
    w.pb(t);
    w.pb(t);
    for(auto &t : w)printf("%d ",t);
    puts("");


}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}