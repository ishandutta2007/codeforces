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
int n,m,fa[10005],c[10005],d[10005],a[10005];
int h[10005],nx[20005],to[20005],M=1;
int ans,res[10005];
int r,b;
bool B[10005];
void dfs(int x,int y){
    d[x]=d[y]+1;
    for(int i=h[x];i;i=nx[i]){
        int z=to[i];
        if(y==z)fa[x]=i>>1;
        else if(d[z]){
            if(d[z]<d[x]){
                if((d[z]^d[x])&1)--a[x],++a[z];
                else ++b,res[1]=i>>1,++a[x],--a[z];
            }
        }
        else dfs(z,x);
    }
}
void sol(int x,int y){
    d[x]=-1;
    for(int i=h[x];i;i=nx[i]){
        int z=to[i];
        if(~d[z]){
            sol(z,x);
            a[x]+=a[z];
        }
    }
    if(a[x]==b)res[++ans]=fa[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        nx[++M]=h[x];
        h[x]=M;
        to[M]=y;
        nx[++M]=h[y];
        h[y]=M;
        to[M]=x;
    }
    for(int i=1;i<=n;++i){
        if(d[i]) continue;
        b=0;
        dfs(i,0);
        if(b){
            if(r){
                puts("0");
                return 0;
            }
            r=i;
            if(b==1)ans=1;
            sol(i,0);
        }
    }
    if(!r){
        printf("%d\n",m);
        if(m){
            for(int i=1;i<m;++i)printf("%d ",i);
            printf("%d\n",m);
        }
        return 0;
    }
    for(int i=1;i<=ans;++i)B[res[i]]=1;
    printf("%d\n",ans);
    ans=0;
    for(int i=1;i<=m;++i)if(B[i])res[++ans]=i;
    if(ans){
        for(int i=1;i<ans;++i)printf("%d ",res[i]);
        printf("%d\n",res[ans]);
    }
   // system("pause");
    return 0;
}