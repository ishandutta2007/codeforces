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
ll a,b,c,l,ans;
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&l);
    if(a<b)swap(a,b);
    if(a<c)swap(a,c);
    for(ll d=0;d<=l;d++){     
           ll o=(a+b+c+d-1)/2;
           if(o<a) continue;
           ans+=(d+1)*(d+2)/2;
           if(a+d>o)ans-=(d-o+a+1)*(d-o+a)/2;
           if(b+d>o)ans-=(d-o+b+1)*(d-o+b)/2;
           if(c+d>o)ans-=(d-o+c+1)*(d-o+c)/2;
    }
    printf("%I64d\n",ans);
   // system("pause");
    return 0;
}