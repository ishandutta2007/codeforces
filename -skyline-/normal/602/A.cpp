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
ll x,y,n,m,bx,by;
int main()
{
    scanf("%I64d%I64d",&n,&bx);
    for(int i=1;i<=n;i++){
            ll o;
            scanf("%I64d",&o);
            x=x*bx+o;
    }
    scanf("%I64d%I64d",&m,&by);
    for(int i=1;i<=m;i++){
            ll o;
            scanf("%I64d",&o);
            y=y*by+o;
    }
    if(x<y)printf("<\n");
    else if(x==y)printf("=\n");
    else printf(">\n");
   // system("pause");
    return 0;
}