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
ll n,a[4003][4003],b[4005];
int main()
{           
    scanf("%I64d",&n);
    for(ll i=1;i<=n+2;i++){
            a[i][1]=a[i][i]=1;
            for(ll j=2;j<i;j++)a[i][j]=(a[i-1][j]+a[i-1][j-1])%1000000007;
    }
    b[0]=1;
    for(ll i=0;i<=n;i++){
            b[i+1]=1;
            for(ll j=1;j<=i;j++)b[i+1]=(b[i+1]+b[j]*a[i+1][j+1])%1000000007;
    }
    printf("%I64d\n",(b[n+1]-b[n]+1000000007)%1000000007);
 //   system("pause");
    return 0;
}