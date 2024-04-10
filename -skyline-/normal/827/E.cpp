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
struct FFT{
    static const int N=1048666,M=998244353ll;
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
        m+=n-2,n=1;
        while(n<=m)n<<=1;
        r=P(n,M-2),w[0]=w2[0]=1,w[1]=w2[n-1]=P(3,(M-1)/n);
        for(int i=2;i<n;++i)w[i]=w2[n-i]=w[i-1]*w[1]%M;
    }
}_;
int f[500005],o[500005];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)f[i]=0;
        for(int i=min(_.N-2,n*4);i>=0;--i)_.a[i]=_.b[i]=0;
        _.n=_.m=n;
        for(int i=0;i<n;++i){
            char c=getchar();
            while(c<33)c=getchar();
            if(c=='V')_.a[i]=1;
            else if(c=='K')_.b[n-i-1]=1;
        }
        _.init(),_.mul();
        for(int i=n-1;i>=0;--i)if(_.a[i])f[n-1-i]=1;
        for(int i=n*2-2;i>=n;--i)if(_.a[i])f[i-n+1]=1;
        int cnt=0;
        for(int i=1;i<=n;++i){
            bool ok=1;
            for(int j=i;j<=n;j+=i)if(f[j])j=n,ok=0;
            if(ok)o[i]=1,++cnt;
            else o[i]=0;
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;++i){
            if(o[i]){
                printf("%d",i);
                if(i<n)putchar(' ');
                else putchar('\n');
            }
        }
    }
	return 0;
}