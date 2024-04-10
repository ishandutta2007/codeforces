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
int n,m,q,a[300005],b[300005],t[2100000],ad[2100000],R,K;
void upd(int k,int l,int r){
    if(r<=R){
        t[k]+=K,ad[k]+=K;
        return;
    }
    int m=(l+r)>>1,lc=k<<1,rc=lc^1;
    if(R>m)upd(rc,m+1,r);
    upd(lc,l,m);
    t[k]=max(t[lc],t[rc])+ad[k];
}
void add(int x,int y){
    R=x,K=y;
    upd(1,1,1048576);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",a+i),add(a[i],1);
    for(int i=1;i<=m;++i)scanf("%d",b+i),add(b[i],-1);
    scanf("%d",&q);
    while(q--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1){
            add(a[y],-1);
            add(z,1);
            a[y]=z;
        }
        else{
            add(b[y],1);
            add(z,-1);
            b[y]=z;
        }
        if(t[1]<=0)printf("-1\n");
        else{
            int k=1,l=1,r=1048576,A=0;
            while(l!=r){
                int m=(l+r)>>1;
                A+=ad[k];
                if(t[k*2+1]+A<=0)r=m,k*=2;
                else l=m+1,k=k*2+1;
            }
            printf("%d\n",l);
        }
    }
    //system("pause");
    return 0;
}