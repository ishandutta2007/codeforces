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
#define orz  998244353ll
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
struct M{
    ll a[2][2];
}t[1048666];
void mul(M &a,M &b,M &c){
    c.a[0][0]=(a.a[0][0]*b.a[0][0]+a.a[0][1]*b.a[1][0])%orz;
    c.a[0][1]=(a.a[0][0]*b.a[0][1]+a.a[0][1]*b.a[1][1])%orz;
    c.a[1][0]=(a.a[1][0]*b.a[0][0]+a.a[1][1]*b.a[1][0])%orz;
    c.a[1][1]=(a.a[1][0]*b.a[0][1]+a.a[1][1]*b.a[1][1])%orz;
}
int n,m,a[500005],f[105],g[105],num[500005];
void bld(int k,int l,int r){
    if(l==r){
        num[l]=k;
        t[k].a[0][0]=0;
        t[k].a[0][1]=g[a[l]*10+a[l+1]];
        t[k].a[1][0]=1;
        t[k].a[1][1]=f[a[l+1]];
        return;
    }
    int lc=k<<1,rc=lc^1,m=(l+r)>>1;
    bld(lc,l,m);bld(rc,m+1,r);
    mul(t[lc],t[rc],t[k]);
}
void out(){
    ll ans=(t[1].a[0][1]+t[1].a[1][1]*f[a[1]])%orz;
    ans=(ans+orz)%orz;
    printf("%I64d\n",ans);
}
void upd(int x){
    int k=num[x];
    t[k].a[0][0]=0;
    t[k].a[0][1]=g[a[x]*10+a[x+1]];
    t[k].a[1][0]=1;
    t[k].a[1][1]=f[a[x+1]];
    while(k>1){
        k>>=1;
        mul(t[k<<1],t[(k<<1)^1],t[k]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%1d",a+i);
    for(int i=0;i<=9;++i)f[i]=i+1;
    for(int i=10;i<=18;++i)g[i]=19-i;
    if(n==1){
        while(m--){
            int x;
            scanf("%d%d",&x,a+1);
            printf("%d\n",f[a[1]]);
        }
        return 0;
    }
    bld(1,1,n-1);
    while(m--){
        int x;
        scanf("%d",&x);
        scanf("%d",a+x);
        if(x>1)upd(x-1);
        if(x<n)upd(x);
        out();
    }
    //system("pause");
    return 0;
}