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
#define orz  1000000007ll
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,m,s,t,p[2005],X,Y,nx[2][2005][2005],xx[2005],yy[2005];
ll x[2005],y[2005],q[2005],a[2005][2005],S[2005][2005],dp[2][2005][2005];
map<ll,int> M;
bool u[2005];
vector<int> v[2005],e[2005];
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;++i)scanf("%d",p+i);
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v[x].pb(y),v[y].pb(x),e[x].pb(z),e[y].pb(z);
    }
    memset(x,-1,sizeof(x));
    memset(u,0,sizeof(u));
    x[s]=0;
    for(int i=1;i<n;++i){
        int k=0;
        for(int j=1;j<=n;++j)if(!u[j]&&x[j]!=-1&&(!k||x[k]>x[j]))k=j;
        u[k]=1;
        for(int j=0;j<v[k].size();++j){
            int _=v[k][j];
            if(u[_]) continue;
            if(x[_]==-1||x[_]>x[k]+e[k][j])x[_]=x[k]+e[k][j];
        }
    }
    memset(y,-1,sizeof(y));
    memset(u,0,sizeof(u));
    y[t]=0;
    for(int i=1;i<n;++i){
        int k=0;
        for(int j=1;j<=n;++j)if(!u[j]&&y[j]!=-1&&(!k||y[k]>y[j]))k=j;
        u[k]=1;
        for(int j=0;j<v[k].size();++j){
            int _=v[k][j];
            if(u[_]) continue;
            if(y[_]==-1||y[_]>y[k]+e[k][j])y[_]=y[k]+e[k][j];
        }
    }
    for(int i=1;i<=n;++i)q[i]=x[i];
    sort(q+1,q+n+1);
    for(int i=1;i<=n;++i)if(i==1||q[i]!=q[i-1])M[q[i]]=++X;
    for(int i=1;i<=n;++i)x[i]=M[x[i]];
    M.clear();
    for(int i=1;i<=n;++i)q[i]=y[i];
    sort(q+1,q+n+1);
    for(int i=1;i<=n;++i)if(i==1||q[i]!=q[i-1])M[q[i]]=++Y;
    for(int i=1;i<=n;++i)y[i]=M[y[i]];
    for(int i=1;i<=n;++i)a[x[i]][y[i]]+=p[i],xx[x[i]]=max(xx[x[i]],(int)y[i]),yy[y[i]]=max(yy[y[i]],(int)x[i]);
    for(int i=X;i;--i){
        for(int j=Y;j;--j)S[i][j]=S[i+1][j]+S[i][j+1]-S[i+1][j+1]+a[i][j];
    }
    for(int i=1;i<=Y;++i)nx[0][X+1][i]=X+1;
    for(int i=1;i<=X;++i)nx[1][i][Y+1]=Y+1;
    for(int i=X;i;--i){
        for(int j=Y;j;--j){
            if(j<=xx[i])nx[0][i][j]=i;
            else nx[0][i][j]=nx[0][i+1][j];
            if(i<=yy[j])nx[1][i][j]=j;
            else nx[1][i][j]=nx[1][i][j+1];
        }
    }
    for(int i=X;i;--i){
        for(int j=Y;j;--j){
            int _=nx[0][i][j]+1;
            dp[0][i][j]=S[i][j]-S[_][j]+max(dp[0][_][j],-dp[1][_][j]);
            _=nx[1][i][j]+1;
            dp[1][i][j]=S[i][j]-S[i][_]+max(dp[1][i][_],-dp[0][i][_]);
        }
    }
    if(dp[0][1][1]>0)puts("Break a heart");
    else if(dp[0][1][1]<0)puts("Cry");
    else puts("Flowers");
    //system("pause");
    return 0;
}