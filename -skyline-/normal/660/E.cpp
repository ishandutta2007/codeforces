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
#define orz  1000000007ll
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//
int n,m;
ll a[1000005],b[1000005];
int main()
{
    scanf("%d%d",&n,&m);
    a[0]=1;
    for(int i=1;i<=n;i++){
            a[i]=m*1ll*(2*a[i-1]-b[i-1]);
            b[i]=b[i-1]*(m-1ll)+a[i-1];
            a[i]=(a[i]+orz)%orz;
            if(a[i]<0)a[i]+=orz;
            b[i]=(b[i]+orz)%orz; 
            if(b[i]<0)b[i]+=orz;
    }
    printf("%I64d\n",a[n]);
//	system("pause");
	return 0;
}