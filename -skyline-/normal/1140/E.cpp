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
int n,k,a[200005];
ll p[200005],f[200005],g[200005],ans=1;
int main(){
    scanf("%d%d",&n,&k);
    p[0]=1,p[1]=k-1;
    for(int i=2;i<=n;++i)p[i]=p[i-1]*p[1]%orz;
    f[0]=1;
    for(int i=1;i<=n;++i)f[i]=(p[i]+orz-f[i-1])%orz;
    g[0]=0;
    for(int i=1;i<=n;++i)g[i]=(p[i]+orz-g[i-1])%orz;
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    int la=-1,cnt=0;
    for(int i=1;i<=n;i+=2){
        if(a[i]==-1)++cnt;
        else{
            if(la==-1)ans=ans*p[cnt]%orz;
            else if(la==a[i])ans=ans*g[cnt]%orz;
            else ans=ans*f[cnt]%orz;
            la=a[i],cnt=0;
        }
    }
    if(la==-1)ans=ans*k%orz*p[cnt-1]%orz;
    else ans=ans*p[cnt]%orz;
    if(n>1){
        int la=-1,cnt=0;
        for(int i=2;i<=n;i+=2){
            if(a[i]==-1)++cnt;
            else{
                if(la==-1)ans=ans*p[cnt]%orz;
                else if(la==a[i])ans=ans*g[cnt]%orz;
                else ans=ans*f[cnt]%orz;
                la=a[i],cnt=0;
            }
        }
        if(la==-1)ans=ans*k%orz*p[cnt-1]%orz;
        else ans=ans*p[cnt]%orz;
    }
    printf("%I64d\n",ans);
  //  system("pause");
    return 0;
}