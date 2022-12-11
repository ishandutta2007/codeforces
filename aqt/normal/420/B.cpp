#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 1e5+5;
int n, k, ps[MN], i, j, x, y, lst[MN];
vi ans; vector<pii> on[MN]; char ch;

int main(){
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;i++){
        scanf(" %c%d",&ch,&x);
        on[x].pb({i,ch=='+'});
    }
    for(i=1;i<=n;i++){
        if(on[i].empty()){
            ans.pb(i);
            continue;
        }
        if(on[i][0].S==0)
            on[i].insert(on[i].begin(),make_pair(0,1));
        if(on[i].back().S==1)
            on[i].pb(make_pair(k+2,0));
        for(auto v : on[i]){
            if(v.S) ps[v.F]++;
            else ps[v.F]--;
        }
    }
    for(i=1;i<=k+1;i++)
        ps[i]+=ps[i-1];
    for(i=0;i<=k+1;i++)
        ps[i]=ps[i]>0?1:0;
    ps[k+2]=0;
    for(i=k+1;i>=0;i--)
        ps[i]+=ps[i+1];
    int tot = ps[0];
    for(i=1;i<=n;i++){
        if(on[i].empty()) continue;
        int sm = 0;
        for(auto v : on[i]){
            if(v.S) sm += ps[v.F];
            else sm -= ps[v.F];
        }
        if(sm==tot) ans.pb(i);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto v : ans)
        printf("%d ",v);
    printf("\n");
    return 0;
}