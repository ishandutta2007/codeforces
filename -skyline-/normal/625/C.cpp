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
int n,k,a[505][505],x,ans;
int main()
{
    scanf("%d%d",&n,&k);
    x=n*n;
    for(int i=1;i<=n;i++){
            for(int j=n;j>=k;j--)a[i][j]=x--;
            ans+=a[i][k];
    }
    for(int i=1;i<=n;i++)for(int j=k-1;j;j--)a[i][j]=x--;
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++)printf("%d ",a[i][j]);
            printf("%d\n",a[i][n]);
    }
	//system("pause");
	return 0;
}