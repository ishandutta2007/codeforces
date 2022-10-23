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
ll n,k,a[300005],f[5002][5002];
int main()
{
    scanf("%I64d%I64d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%I64d",a+i);
    sort(a+1,a+n+1);
    ll d=n/k;
    for(int i=1;i<=k;i++)f[0][i]=999999999999999ll;
    for(int i=1;i<=k;i++){
            f[i][0]=f[i-1][0]+a[d*i]-a[d*i-d+1];
            for(int j=1;j<=k;j++)f[i][j]=min(f[i-1][j]+a[d*i+j]-a[d*i-d+j+1],f[i-1][j-1]+a[d*i+j]-a[d*i-d+j]);
    }
    printf("%I64d\n",f[k][n%k]);               
  //  system("pause");
    return 0;
}