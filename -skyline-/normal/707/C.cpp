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
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
ll x;
int main()
{
    scanf("%I64d",&x);
    if(x<=2){
             printf("-1\n");
             return 0;
    }
    ll o=x,p=1;
    while(!(o&1)){
                  o>>=1;
                  p<<=1;
    }
    if(o==1){
             printf("%I64d %I64d\n",(x/4ll)*3ll,(x/4ll)*5ll);
             return 0;
    }
    ll a=o*1ll*o*1ll-1ll,b=a+2ll;
    a/=2ll;
    b/=2ll;
    printf("%I64d %I64d\n",a*p,b*p);
//	system("pause");
	return 0;
}