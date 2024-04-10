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
#define N    2000000
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,a[2000005],f[2000005],g[2000005],b[2000005],p[2000005],c[2000005];
ll ans=1;
bool ok;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int o;
        scanf("%d",&o);
        ++a[o];
    }
    for(int i=N;i;--i){
        if(!a[i]) continue;
        if(a[i]>2)ok=1;
        if(a[i]>1){
            f[i]=f[i-1]=1;
            continue;
        }
        bool fl=0;
        for(int j=i;j<=N;j+=i)if(f[j])fl=1,j=N;
        if(fl)f[i-1]=1;
        else f[i]=1;
    }
    if(f[1])ok=1;
    for(int i=2;i<=N;++i){
        if(p[i]) continue;
        for(int j=i+i;j<=N;j+=i)p[j]=1;
    }
    for(int i=N;i>=2;--i){
        if(p[i]) continue;
        p[i]=i;
        int t=i;
        while(t<=N/i)t*=i,p[t]=i;
    }
    for(int i=N;i>1;--i){
        if(p[i]==1) continue;
        int fl=0;
        for(int j=i+i;j<=N;j+=i)if(b[j])fl=1,j=N;
        if(fl) continue;
        for(int j=i;j<=N;j+=i)if(f[j])++fl;
        if(fl==1){
            for(int j=i;j<=N;j+=i)if(f[j])g[j]=1;
        }
        if(fl)b[i]=1;
    }
    for(int i=2;i<=N;++i)if(f[i]&&!g[i])ok=1;
    for(int i=2;i<=N;++i)if(b[i])ans=ans*1ll*i%orz;
    if(ok)ans=(ans+1ll)%orz;
    ans=(ans%orz+orz)%orz;
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}