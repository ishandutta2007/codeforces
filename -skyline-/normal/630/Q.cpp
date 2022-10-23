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
double a,ans;
int main()
{
    cin>>a;
    ans+=a*a*a*0.11785113019775792073347406035081;
    cin>>a;
    ans+=a*a*a*0.23570226039551584146694812070162;
    cin>>a;
    double b=0.5*a/0.72654252800536088589546675748062;
    double x=0.5*a*1.7320508075688772935274463415059;
    ans+=2.5*a*b*sqrt(x*x-b*b)/3;
    printf("%.20lf\n",ans);
//	system("pause");
	return 0;
}