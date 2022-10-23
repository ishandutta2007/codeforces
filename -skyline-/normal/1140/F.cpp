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
int n,_l,_r,_x,_y,f[600005],siz[600005],cx[600005],cy[600005];
ll ans[300005],res;
vector<int> vx[1048666],vy[1048666],Vx,Vy;
map<ll,int> m;
void ins(int k,int l,int r){
    if(_l<=l&&_r>=r){
        vx[k].pb(_x),vy[k].pb(_y+300000);
        return;
    }
    int m=(l+r)>>1,lc=k<<1,rc=lc^1;
    if(_l<=m)ins(lc,l,m);
    if(_r>m)ins(rc,m+1,r);
}
void solve(int k,int l,int r){
    vector<int> X,Y;
    for(int i=0;i<vx[k].size();++i){
        int x=vx[k][i],y=vy[k][i];
        while(f[x]!=x)x=f[x];
        while(f[y]!=y)y=f[y];
        if(x==y) continue;
        if(siz[x]<siz[y]) swap(x,y);
        X.pb(x),Y.pb(y);
        f[y]=x;
        siz[x]+=siz[y];
        res-=cx[x]*1ll*cy[x]+cx[y]*1ll*cy[y];
        cx[x]+=cx[y],cy[x]+=cy[y];
        res+=cx[x]*1ll*cy[x];
    }
    if(l==r)ans[l]=res;
    else{
        int m=(l+r)>>1;
        solve(k<<1,l,m);
        solve((k<<1)^1,m+1,r);
    } 
    for(int i=((int)X.size())-1;i>=0;--i){
        int x=X[i],y=Y[i];
        f[y]=y;
        siz[x]-=siz[y];
        res-=cx[x]*1ll*cy[x];
        cx[x]-=cx[y],cy[x]-=cy[y];
        res+=cx[x]*1ll*cy[x]+cx[y]*1ll*cy[y];
    }        
}
int main(){
    for(int i=1;i<=600000;++i)f[i]=i,siz[i]=1;
    for(int i=1;i<=300000;++i)cx[i]=1;
    for(int i=300001;i<=600000;++i)cy[i]=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        ll _=x*1000000ll+y;
        int o=m[_];
        if(!o)Vx.pb(x),Vy.pb(y);
        if(o<=0)m[_]=i;
        else _l=o,_r=i-1,_x=x,_y=y,ins(1,1,n),m[_]=-1;
    }
    for(int i=0;i<Vx.size();++i){
        int o=m[Vx[i]*1000000ll+Vy[i]];
        if(o!=-1)_l=o,_r=n,_x=Vx[i],_y=Vy[i],ins(1,1,n);
    }
    solve(1,1,n);
    for(int i=1;i<n;++i)printf("%I64d ",ans[i]);
    printf("%I64d\n",ans[n]);
  //  system("pause");
    return 0;
}