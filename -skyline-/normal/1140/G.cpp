//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,f[300005][19],d[300005];
ll a[300005][2],b[300005],dp[300005][19][2][2];
vector<int> v[300005];
vector<ll> e1[300005],e2[300005];
void dfs(int x,int y){
    d[x]=d[y]+1,f[x][0]=y;
    for(int i=0;i<18;++i)f[x][i+1]=f[f[x][i]][i];
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==y)a[x][0]=e1[x][i],a[x][1]=e2[x][i];
        else dfs(v[x][i],x);
    }
}
void upd(int x,int y){
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==y) continue;
        upd(v[x][i],x);
        b[x]=min(b[x],e1[x][i]+b[v[x][i]]+e2[x][i]);
    }
}
void upd2(int x,int y){
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==y) continue;
        b[v[x][i]]=min(b[v[x][i]],e1[x][i]+b[x]+e2[x][i]);
        upd2(v[x][i],x);
    }
}
void ope(int x,int y){
    dp[x][0][0][0]=min(a[x][0],b[x]+a[x][1]+b[y]);
    dp[x][0][0][1]=min(a[x][0]+b[y],b[x]+a[x][1]);
    dp[x][0][1][0]=min(a[x][1]+b[y],b[x]+a[x][0]);
    dp[x][0][1][1]=min(a[x][1],b[x]+a[x][0]+b[y]);
    for(int i=0;i<18;++i){
        int _=f[x][i];
        dp[x][i+1][0][0]=min(dp[x][i][0][0]+dp[_][i][0][0],dp[x][i][0][1]+dp[_][i][1][0]);
        dp[x][i+1][0][1]=min(dp[x][i][0][0]+dp[_][i][0][1],dp[x][i][0][1]+dp[_][i][1][1]);
        dp[x][i+1][1][0]=min(dp[x][i][1][0]+dp[_][i][0][0],dp[x][i][1][1]+dp[_][i][1][0]);
        dp[x][i+1][1][1]=min(dp[x][i][1][0]+dp[_][i][0][1],dp[x][i][1][1]+dp[_][i][1][1]);
    }
    for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)ope(v[x][i],x);
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    for(int i=18;i>=0;--i)if(d[f[x][i]]>=d[y])x=f[x][i];
    if(x==y) return x;
    for(int i=18;i>=0;--i)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
pair<ll,ll> up(int x,int y,int z){
    ll res[2]={0,0};
    res[z^1]=b[x];
    for(int i=18;i>=0;--i){
        if(d[f[x][i]]<d[y]) continue;
        ll X,Y;
        X=min(res[0]+dp[x][i][0][0],res[1]+dp[x][i][1][0]);
        Y=min(res[0]+dp[x][i][0][1],res[1]+dp[x][i][1][1]);
        res[0]=X,res[1]=Y,x=f[x][i];
    }
    return mp(res[0],res[1]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%I64d",b+i);
    for(int i=1;i<n;++i){
        int x,y;
        ll p,q;
        scanf("%d%d%I64d%I64d",&x,&y,&p,&q);
        v[x].pb(y),v[y].pb(x),e1[x].pb(p),e1[y].pb(p),e2[x].pb(q),e2[y].pb(q);
    }
    dfs(1,0);
    upd(1,0);
    upd2(1,0);
    ope(1,0);
    int T;
    scanf("%d",&T);
    while(T--){
        int x,y,z,X,Y;
        scanf("%d%d",&x,&y);
        if(x&1)X=0;
        else X=1;
        if(y&1)Y=0;
        else Y=1;
        x=(x+1)>>1,y=(y+1)>>1;
        z=lca(x,y);
        pair<ll,ll> xx=up(x,z,X),yy=up(y,z,Y);
        ll ans;
        ans=min(xx.first+yy.first,xx.second+yy.second);
        printf("%I64d\n",ans);
    }
   // system("pause");
    return 0;
}