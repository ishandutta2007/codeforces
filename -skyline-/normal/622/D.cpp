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
int n,a[1000005];
int main()
{
    scanf("%d",&n);
    int l=1,r=n;
    for(int i=1;i<n;i+=2)a[l++]=i,a[r--]=i;
    l=n+2,r=n<<1;
    for(int i=2;i<n;i+=2)a[l++]=i,a[r--]=i;
    for(int i=1;i<=(n<<1);i++)if(!a[i])a[i]=n;
    n<<=1;
    for(int i=1;i<n;i++)printf("%d ",a[i]);
    printf("%d\n",a[n]);
//	system("pause");
	return 0;
}