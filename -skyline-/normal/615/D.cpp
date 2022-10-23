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
//:
using namespace std;
ll n,m=1000000007ll,a[200005],o=1ll,k=-1ll;
ll ope(ll x,ll k){
          ll ans=1ll;
          while(k){
                   if(k&1)ans*=x,ans%=m;
                   k>>=1;
                   x=x*x%m;
          }
          return ans;
}
int main()
{
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++){
            ll t;
            scanf("%I64d",&t);
            o=o*t;
            o%=m;
            a[t]++;
    }
    for(int i=1;i<=200000;i++)if(a[i]&1)k=i;
    if(k==-1){
              o=1ll;
              for(int i=1;i<=200000;i++)o*=ope(i,a[i]>>1),o%=m;
              for(int i=1;i<=200000;i++)o=ope(o,a[i]+1);
    }
    else{
         o=ope(o,(a[k]+1)>>1);
         a[k]=0;
         for(int i=1;i<=200000;i++)o=ope(o,a[i]+1);
    }
    printf("%I64d\n",o);
  //  system("pause");
    return 0;
}