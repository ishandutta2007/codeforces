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
#define S    4194304
using namespace std;
char I[S+1],*Is=I,*It=I;
inline char gc(){return Is==It?((It=(Is=I)+fread(I,1,S,stdin))==I?EOF:*Is++):*Is++;}
inline int get(){
    int x=0,o=1;
    char c=gc();
    while(c<'-')c=gc();
    if(c=='-')o=-1,c=gc();
    while(c>47)x=x*10+c-48,c=gc();
    return x*o;
}
struct T{int x[3],d[3],k[3],l,r,id;}t[100005];
int m,n,r,D,nx[3]={1,2,0},L,R,X,Y;
int p[100005],s[100005],b[100005],inc[100005],pre[100005],ans[100005],add[100005],out[100005];
inline bool cmp(T x,T y){return x.k[D]<y.k[D];}
void upd(int k){
    if(t[k].l){
        if(t[t[k].l].x[0]<t[k].x[0])t[k].x[0]=t[t[k].l].x[0];
        if(t[t[k].l].x[1]<t[k].x[1])t[k].x[1]=t[t[k].l].x[1];
        if(t[t[k].l].x[2]<t[k].x[2])t[k].x[2]=t[t[k].l].x[2];
        if(t[t[k].l].d[0]>t[k].d[0])t[k].d[0]=t[t[k].l].d[0];
        if(t[t[k].l].d[1]>t[k].d[1])t[k].d[1]=t[t[k].l].d[1];
        if(t[t[k].l].d[2]>t[k].d[2])t[k].d[2]=t[t[k].l].d[2];
    }
    if(t[k].r){
        if(t[t[k].r].x[0]<t[k].x[0])t[k].x[0]=t[t[k].r].x[0];
        if(t[t[k].r].x[1]<t[k].x[1])t[k].x[1]=t[t[k].r].x[1];
        if(t[t[k].r].x[2]<t[k].x[2])t[k].x[2]=t[t[k].r].x[2];
        if(t[t[k].r].d[0]>t[k].d[0])t[k].d[0]=t[t[k].r].d[0];
        if(t[t[k].r].d[1]>t[k].d[1])t[k].d[1]=t[t[k].r].d[1];
        if(t[t[k].r].d[2]>t[k].d[2])t[k].d[2]=t[t[k].r].d[2];
    }
}
int build(int l,int r,int d){
    int m=(l+r)>>1;
    D=d;
    nth_element(t+l+1,t+m+1,t+r+1,cmp);
    if(l!=m)t[m].l=build(l,m-1,nx[d]);
    if(r!=m)t[m].r=build(m+1,r,nx[d]);
    t[m].x[0]=t[m].d[0]=t[m].k[0];
    t[m].x[1]=t[m].d[1]=t[m].k[1];
    t[m].x[2]=t[m].d[2]=t[m].k[2];
    upd(m);
    return m;
}
void sol(int x){
    if(t[x].x[0]>=L&&t[x].d[0]<=R&&t[x].x[1]>=X&&t[x].x[2]>=Y){
        ++add[x];
        return;
    }
    if(t[x].d[0]<L||t[x].x[0]>R||t[x].d[1]<X||t[x].d[2]<Y) return;
    if(t[x].k[0]>=L&&t[x].k[0]<=R&&t[x].k[1]>=X&&t[x].k[2]>=Y)++ans[x];
    if(t[x].l)sol(t[x].l);
    if(t[x].r)sol(t[x].r);
}
void dfs(int x){
    ans[x]+=add[x];
    if(t[x].l)add[t[x].l]+=add[x],dfs(t[x].l);
    if(t[x].r)add[t[x].r]+=add[x],dfs(t[x].r);
}
int main(){
    m=get();n=get();
    for(int i=1;i<=m;++i)p[i]=get();
    for(int i=1;i<=m;++i)s[i]=get();
    for(int i=1;i<=m;++i)b[i]=get();
    for(int i=1;i<=n;++i)inc[i]=get();
    for(int i=1;i<=n;++i)pre[i]=get();
    for(int i=1;i<=n;++i)t[i].k[0]=inc[i],t[i].k[1]=inc[i]+pre[i],t[i].k[2]=inc[i]-pre[i],t[i].id=i;
    r=build(1,n,0);
    for(int i=1;i<=m;++i){
        L=p[i],R=s[i],X=b[i]+p[i],Y=p[i]-b[i];
        sol(r);
    }
    dfs(r);
    for(int i=1;i<=n;++i)out[t[i].id]=ans[i];
    for(int i=1;i<n;++i)printf("%d ",out[i]);
    printf("%d\n",out[n]);
    //system("pause");
    return 0;
}