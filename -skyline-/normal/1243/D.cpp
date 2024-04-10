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
using namespace std;
int n,m,f[262222],ans,L,R,I,cnt[262222],u[262222];
vector<int> v[100005];
int get(int x){return x==f[x]?x:f[x]=get(f[x]);}
void dsu(int x,int y){
    if(get(x)==get(y)) return;
    f[f[x]]=f[y];
}
void dfs(int k,int l,int r){
    if(l>=L&&r<=R){
        u[k]=1;
        dsu(I,k);
        return;
    }
    int m=(l+r)>>1;
    if(L<=m)dfs(k<<1,l,m);
    if(R>m)dfs((k<<1)^1,m+1,r);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)v[i].pb(0);
    for(int i=1;i<=262143;++i)f[i]=i;
    for(int i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=n;++i)sort(v[i].begin(),v[i].end()),v[i].pb(n+1);
    for(int i=1;i<=n;++i){
        I=i+131071;
        for(int j=1;j<v[i].size();++j){
            L=v[i][j-1]+1,R=v[i][j]-1;
            if(L<=R)dfs(1,1,131072);
        }
    }
    for(int i=1;i<=131071;++i){
        if(!u[i]) continue;
        int lc=i<<1,rc=lc^1;
        u[lc]=u[rc]=1;
        dsu(i,lc),dsu(i,rc);
    }
    for(int i=1;i<=n;++i)cnt[get(131071+i)]=1;
    for(int i=1;i<=131071+n;++i)ans+=cnt[i];
    printf("%d\n",ans-1);
    //system("pause");
    return 0;
}