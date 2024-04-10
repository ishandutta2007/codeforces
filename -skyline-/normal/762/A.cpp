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
ll n,a[1000005];
int k,s;
int main()
{
    scanf("%I64d%d",&n,&k);
    if(n==1){
             if(k==1)printf("1\n");
             else printf("-1\n");
             return 0;
    }
    for(ll i=1;i*i<=n;i++){
           if(n%i) continue;
           a[++s]=i;
    }
    if(s>=k)printf("%I64d\n",a[k]);
    else if(a[s]*a[s]==n&&k>=2*s)printf("-1\n");
    else if(a[s]*a[s]!=n&&k>2*s)printf("-1\n");
    else if(a[s]*a[s]==n)printf("%I64d\n",n/a[s+s-k]);
    else printf("%I64d\n",n/a[s+s+1-k]);
//	system("pause");
	return 0;
}