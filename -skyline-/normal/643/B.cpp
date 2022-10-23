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
int n,k,a,b,c,d,e;
int main()
{
    scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d);
    if(n>=k||n==4){
                   printf("-1\n");
                   return 0;
    }
    for(int i=1;i<=n;i++)if(i!=a&&i!=b&&i!=c&&i!=d)e=i,i=n+1;
    printf("%d ",a);
    for(int i=1;i<=n;i++)if(i!=a&&i!=b&&i!=c&&i!=d&&i!=e)printf("%d ",i);
    printf("%d %d %d %d\n",c,e,d,b);
    printf("%d ",c);
    for(int i=n;i;i--)if(i!=a&&i!=b&&i!=c&&i!=d&&i!=e)printf("%d ",i);
    printf("%d %d %d %d\n",a,e,b,d);
//	system("pause");
	return 0;
}