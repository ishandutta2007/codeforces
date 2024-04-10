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
ll d,k,a,b,t;
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d",&d,&k,&a,&b,&t);
    ll o=k*a+t;
    ll p=d/k;
    if(d>k)p=p*o+(d%k)*b-t;
    else p=a*d;
    ll ans=min(p,b*d);
    if(d>k)ans=min(ans,a*k+b*(d-k));
    p=d/k;
    if(d>k)ans=min(p*o+(d%k)*a,ans);
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}