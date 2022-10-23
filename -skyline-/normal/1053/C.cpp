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
//524288
int n,q,a[200005];
ll t[524333],w[200005];
struct T{
    ll t[200005];
    void add(int x,ll k){while(x<=n)t[x]+=k,x+=(x&-x);}
    ll sum(int x){
        ll s=0;
        while(x)s+=t[x],x-=(x&-x);
        return s;
    }
    ll get(int l,int r){return sum(r)-sum(l-1);}
}f1,f2;
int fnd(int k,ll o){
    if(k>262143) return k-262143;
    int lc=k<<1;
    if(t[lc]>=o) return fnd(lc,o);
    return fnd(lc^1,o-t[lc]);
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",a+i),a[i]=a[i]-i+1;
    for(int i=1;i<=n;++i){
        scanf("%I64d",w+i);
        t[262143+i]=w[i];
        f1.add(i,w[i]);
        f2.add(i,w[i]*1ll*a[i]%orz);
    }
    for(int i=262143;i;--i)t[i]=t[i<<1]+t[(i<<1)^1];
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l<0){
            l=-l;
            f1.add(l,-w[l]);
            f2.add(l,-(w[l]*1ll*a[l]%orz));
            w[l]=r;
            f1.add(l,w[l]);
            f2.add(l,w[l]*1ll*a[l]%orz);
            int k=l+262143;
            t[k]=r;
            do{
                k>>=1;
                t[k]=t[k<<1]+t[(k<<1)^1];
            }while(k>1);
            continue;
        }
        ll L=f1.sum(l-1),R=f1.sum(r),O=R-L;
        int k=fnd(1,L+(O+1ll)/2ll);
        ll ans=a[k]*1ll*(f1.get(l,k-1)%orz)%orz-f2.get(l,k-1)%orz+f2.get(k+1,r)%orz-a[k]*1ll*(f1.get(k+1,r)%orz)%orz;
        ans=(ans%orz+orz)%orz;
        printf("%I64d\n",ans);
    }
//	system("pause");
	return 0;
}