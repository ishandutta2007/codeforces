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
ll x,a[4000005],b[4000005],k,add,divi,ans;
int main()
{
    scanf("%I64d",&x);
    for(ll i=1;i<=20000000;i++){
           add+=(i-2)*(i-1)/2+i-1;
           divi=i*(i+1)/2;
           ans=(x+add)/divi;
           if(ans<i) break;
           if(ans*divi==x+add)a[++k]=i,b[k]=ans;
    }
    printf("%I64d\n",a[k]==b[k]?k*2-1:k*2);
    for(int i=1;i<=k;i++)printf("%I64d %I64d\n",a[i],b[i]);
    for(int i=(a[k]==b[k]?k-1:k);i;i--)printf("%I64d %I64d\n",b[i],a[i]);
  //  system("pause");
    return 0;
}