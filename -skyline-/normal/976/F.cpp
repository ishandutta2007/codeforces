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
int n1,n2,m,z[2005],b[2005],d1[2005],d2[2005],d,x[2005],y[2005];
vector<int> out[2005];
struct E{int x,y,z;};
struct F{
    int n,s,t,i[4100],l[4100],ans,q[4100];
    vector<E> v[4100];
    void init(){
        for(int i=1;i<=n;++i)v[i].clear();
    }
    void add(int x,int y,int z){
        E X,Y;
        X.x=y,X.y=z,X.z=v[y].size();
        Y.x=x,Y.y=0,Y.z=v[x].size();
        v[x].pb(X),v[y].pb(Y);
    }
    void bfs(){
        memset(l,-1,sizeof(l));
        int qs=0,qe=1;
        l[s]=0,q[1]=s;
        while(qs!=qe){
            int k=q[++qs];
            for(int i=0;i<v[k].size();++i){
                if(l[v[k][i].x]==-1&&v[k][i].y)q[++qe]=v[k][i].x,l[v[k][i].x]=l[k]+1;
            }
        }
    }
    int dfs(int x,int y){
        if(x==t){
            ans+=y;
            return y;
        }
        for(;i[x]<v[x].size();++i[x]){
            E &o=v[x][i[x]];
            if(o.y&&l[o.x]>l[x]){
                int d=dfs(o.x,min(o.y,y));
                if(d){
                    o.y-=d,v[o.x][o.z].y+=d;
                    return d;
                }
            }
        }
        return 0;
    }
    int flow(){
        ans=0;
        while(1){
            bfs();
            if(l[t]==-1) return ans;
            memset(i,0,sizeof(i));
            while(dfs(s,orz));
        }
    }
}_;
int r(){
    int x=0;
    char c=getchar();
    while(c<48)c=getchar();
    while(c>47)x=x*10+c-48,c=getchar();
    return x;
}
int W[12],B;
void w(int x){
    if(!x){putchar('0');return;}
    while(x)W[++B]=x%10,x/=10;
    while(B)putchar(48+W[B--]);
}
int main(){
    n1=r();n2=r();m=r();
    _.n=n1+n2+2,_.s=_.n-1,_.t=_.n;
    for(int i=1;i<=m;++i){
        x[i]=r();y[i]=r();
        _.add(x[i],y[i]+n1,1);
        z[i]=_.v[x[i]].size()-1;
        ++d1[x[i]],++d2[y[i]];
    }
    d=m;
    for(int i=1;i<=n1;++i)d=min(d,d1[i]);
    for(int i=1;i<=n2;++i)d=min(d,d2[i]);
    for(int i=1;i<=n1;++i)_.add(_.s,i,d1[i]-d);
    for(int i=1;i<=n2;++i)_.add(n1+i,_.t,d2[i]-d);
    putchar('0');putchar('\n');
    for(int i=d;i;--i){
        _.flow();
        memset(b,0,sizeof(b));
        int s=0;
        for(int j=1;j<=m;++j)if(_.v[x[j]][z[j]].y)b[j]=1,++s;
        out[i].pb(s);
        for(int j=1;j<=m;++j)if(b[j])out[i].pb(j);
        for(int j=0;j<_.v[_.s].size();++j)++_.v[_.s][j].y;
        for(int j=0;j<_.v[_.t].size();++j)++_.v[_.v[_.t][j].x][_.v[_.t][j].z].y;
    }
    for(int i=1;i<=d;++i){
        w(out[i][0]);
        for(int j=1;j<out[i].size();++j)putchar(' '),w(out[i][j]);
        putchar('\n');
    }
	return 0;
}