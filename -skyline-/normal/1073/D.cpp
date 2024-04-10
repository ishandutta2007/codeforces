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
int n,a[400005],t2[400005];
ll k,s,ans,t[1048666];
void add2(int x,int k){while(x<=n*2)t2[x]+=k,x+=(x&-x);}
int get2(int x){
    int s=0;
    while(x)s+=t2[x],x-=(x&-x);
    return s;
}
ll get(int k,int l,int r,int L,int R){
    if(l>R||L>r) return 0;
    if(l>=L&&r<=R) return t[k];
    int m=(l+r)>>1;
    return get(k<<1,l,m,L,R)+get((k<<1)^1,m+1,r,L,R);
}
int fnd(int k,ll o){
    if(k>524287) return k-524287;
    int lc=k<<1;
    if(t[lc]>o) return fnd(lc,o);
    return fnd(lc^1,o-t[lc]);
}
int main(){
    scanf("%d%I64d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        s+=a[i],a[n+i]=a[i],t[524287+i]=t[524287+n+i]=a[i],add2(i,1),add2(n+i,1);
    }
    for(int i=524287;i;--i)t[i]=t[i<<1]+t[(i<<1)^1];
    int l=1;
    for(int _=n;_;--_){
        ans+=k/s*_,k%=s;
        if(!k) break;
        int x=fnd(1,k+get(1,1,524288,1,l-1));
        int X=(x<=n?x+n:x-n);
        ans+=get2(x-1)-get2(l-1);
        add2(x,-1),add2(X,-1),s-=t[x+524287];
        int I,o;
        I=524287+x,o=t[I];
        while(I)t[I]-=o,I>>=1;
        I=524287+X,o=t[I];
        while(I)t[I]-=o,I>>=1;
        k-=get(1,1,524288,l,x);
        l=min(x,X);
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}