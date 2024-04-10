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
struct FFT{
    static const int N=2100000,M=998244353ll;
    int n,m;
    ll a[N],b[N],w[N],w2[N],r;
    ll P(ll x,ll k){
        ll ans=1;
        while(k){
            if(k&1)ans=ans*x%M;
            x=x*x%M,k>>=1;
        }
        return ans;
    }
    void fft(ll *a,ll *w){
        for(int i=0,j=0;i<n;++i){
            if(i<j)swap(a[i],a[j]);
            for(int k=n>>1;(j^=k)<k;k>>=1);
        }
        for(int i=2;i<=n;i<<=1){
            for(int j=0;j<n;j+=i){
                for(int k=0;k<(i>>1);++k){
                    int l=j+k,r=l+(i>>1);
                    ll o=a[r]*w[n/i*k]%M;
                    a[r]=(a[l]+M-o)%M,a[l]=(a[l]+o)%M;
                }
            }
        }
    }
    void mul(){
        fft(a,w),fft(b,w);
        for(int i=0;i<n;++i)a[i]=a[i]*b[i]%M*r%M;
        fft(a,w2);
    }
    void init(){
        int nn=n+1,mm=m+1;
        m+=n,n=1;
        while(n<=m)n<<=1;
        for(int i=nn;i<n;++i)a[i]=0;
        for(int i=mm;i<n;++i)b[i]=0;
        r=P(n,M-2),w[0]=w2[0]=1,w[1]=w2[n-1]=P(3,(M-1)/n);
        for(int i=2;i<n;++i)w[i]=w2[n-i]=w[i-1]*w[1]%M;
    }
}_;
struct D{
    int n;
    ll a[2100000];
    void m(){
        while(!a[n])--n;
    }
}ans,x;
int n,k;
int main(){
    ans.n=0,ans.a[0]=1;
    x.n=9;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i){
        int X;
        scanf("%d",&X);
        x.a[X]=1;
    }
    x.m();
    n>>=1;
    while(n){
        if(n&1){
            _.n=x.n;
            _.m=ans.n;
            for(int i=0;i<=x.n;++i)_.a[i]=x.a[i];
            for(int i=0;i<=ans.n;++i)_.b[i]=ans.a[i];
            _.init();
            _.mul();
            ans.n=_.m;
            for(int i=0;i<=ans.n;++i)ans.a[i]=_.a[i];
            ans.m();
        }
        n>>=1;
        if(!n) break;
        _.n=_.m=x.n;
        for(int i=0;i<=x.n;++i)_.a[i]=_.b[i]=x.a[i];
        _.init();
        _.mul();
        x.n=_.m;
        for(int i=0;i<=x.n;++i)x.a[i]=_.a[i];
        x.m();
    }
    ll o=0;
    for(int i=0;i<=ans.n;++i)o+=ans.a[i]*ans.a[i]%orz;
    printf("%I64d\n",(o%orz+orz)%orz);
//	system("pause");
	return 0;
}