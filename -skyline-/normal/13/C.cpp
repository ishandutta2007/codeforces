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
#define orz  100000000000007ll
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//
int a[5005],b[5005],n;
ll f[2][5005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
            int o=i&1;
            f[o][0]=orz;
            for(int j=1;j<=n;j++)f[o][j]=min(f[o][j-1],f[o^1][j]+abs(a[i]-b[j]));
    }
    printf("%I64d\n",f[n&1][n]);       
//	system("pause");
	return 0;
}