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
int n;
ll a[2005],b[10015],c[10015],d[10015];
long double ans,q;
int main()
{
    scanf("%d",&n);
    q=(n*(n-1.0))/2.0;
    for(int i=1;i<=n;i++)scanf("%I64d",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++)b[a[j]-a[i]]++;
    }
    for(int i=10002;i;i--)c[i]=c[i+1]+b[i];
    for(int i=0;i<=10002;i++)d[i]=c[i+1];
    for(int i=1;i<=5000;i++){
            for(int j=1;j<=5000;j++)ans+=(ll)b[i]*b[j]*d[i+j];
    }
    long double out=(long double)ans;
    out/=q;
    out/=q;
    out/=q;
    double res=(double)out;
    printf("%.18lf\n",res);
	//system("pause");
	return 0;
}