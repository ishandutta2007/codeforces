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
//:
using namespace std;
int n,m,t[200005],D[200005],s[200005],num[600005],dis[600005],root[200005],sum[200005];
ll u[200005],d[200005],ans[200005],ANS,cnt[200005];
vector<int> V[200005],E[200005],roots,v[200005],e[200005];
void dfs(int x){
    s[x]=1;
    for(int i=0;i<v[x].size();++i)sum[v[x][i]]=sum[x]+e[x][i],dfs(v[x][i]),s[x]+=s[v[x][i]],d[x]+=d[v[x][i]]+e[x][i]*s[v[x][i]];
}
void dfs2(int x,int p){
    ans[x]=u[x]+d[x],root[x]=p;
    for(int i=0;i<v[x].size();++i)u[v[x][i]]=ans[x]+(s[p]-s[v[x][i]]*2)*e[x][i]-d[v[x][i]],dfs2(v[x][i],p);
}
void addtrees(int x,int p){for(int i=0;i<V[x].size();++i)if(t[V[x][i]]==1&&V[x][i]!=p)v[x].pb(V[x][i]),e[x].pb(E[x][i]),addtrees(V[x][i],x);}
void addroots(int x){
    if(t[x]) return;
    roots.pb(x),t[x]=2,addtrees(x,x),dfs(x),dfs2(x,x),num[++m]=s[x],ANS+=ans[x];
    for(int i=0;i<V[x].size();++i)addroots(V[x][i]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        V[x].pb(y),V[y].pb(x),E[x].pb(z),E[y].pb(z);
    }
    queue<int> Q;
    for(int i=1;i<=n;++i){
        D[i]=V[i].size();
        if(D[i]==1)Q.push(i);
    }
    while(!Q.empty()){
        int x=Q.front();
        Q.pop(),t[x]=1;
        for(int i=0;i<V[x].size();++i)if((--D[V[x][i]])==1)Q.push(V[x][i]);
    }
    for(int i=1;i<=n;++i)addroots(i);
    roots.pb(roots[0]);
    for(int i=1;i<=m;++i){
        for(int j=0;j<V[roots[i]].size();++j)if(V[roots[i]][j]==roots[i-1])dis[i]=E[roots[i]][j];
    }
    for(int i=1;i<=m;++i)num[i+m+m]=num[i+m]=num[i],dis[i+m+m]=dis[i+m]=dis[i];
    for(int i=2;i<=m*3;++i)num[i]+=num[i-1],dis[i]+=dis[i-1];
    int L=2,R=m+1;
    ll S=0;
    for(int i=2;i<=m;++i)S+=(dis[m]-dis[i-1])*(num[i]-num[i-1]);
    for(int i=1;i<=m;++i){
        if(R<m+i)++L,++R,S-=(dis[m+i-1]-dis[i-1])*(num[i]-num[i-1]);
        while((dis[R]+dis[L-1])<dis[m+i-1]*2&&L<m+i)S+=(dis[R]+dis[L-1]-dis[m+i-1]*2)*(num[L]-num[L-1]),++L,++R;
        cnt[roots[i-1]]=S,S-=(num[R]+num[L-1]-num[m+i]*2)*(dis[i]-dis[i-1]);
    }
    for(int i=1;i<=n;++i)printf("%I64d ",ans[i]+ANS-ans[root[i]]+(n-s[root[i]])*1ll*sum[i]+cnt[root[i]]);
 //   system("pause");
	return 0;
}