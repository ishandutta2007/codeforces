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
int n,f[55][55],k;
bool x[55];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)scanf("%d",f[i]+j);
    }
    for(int i=1;i<=n;i++){
            bool b=1;
            memset(x,0,sizeof(x));
            for(int j=1;j<=n;j++)x[f[i][j]]=1;
            for(int j=1;j<n;j++)if(!x[j])b=0;
            if(b)k=i,i=n+1;
    }
    f[k][k]=n;
    for(int i=1;i<n;i++)printf("%d ",f[k][i]);
    printf("%d\n",f[k][n]);
//	system("pause");
	return 0;
}