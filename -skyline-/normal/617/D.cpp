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
int a,b,c,d,e,f,ans;
int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(a==c&&c==e)ans=1;
    else if(b==d&&d==f)ans=1;
    else if(a==c&&(min(b,d)>=f||max(b,d)<=f))ans=2;
    else if(a==e&&(min(b,f)>=d||max(b,f)<=d))ans=2;
    else if(c==e&&(min(d,f)>=b||max(d,f)<=b))ans=2;
    else if(b==d&&(min(a,c)>=e||max(a,c)<=e))ans=2;
    else if(b==f&&(min(a,e)>=c||max(a,e)<=c))ans=2;
    else if(d==f&&(min(c,e)>=a||max(c,e)<=a))ans=2;
    else ans=3;
    printf("%d\n",ans);
//	system("pause");
	return 0;
}