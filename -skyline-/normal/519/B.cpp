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
//:
using namespace std;
int n,a[100005],b[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)scanf("%d",b+i);
    sort(b+1,b+n);
    b[n]=2147483640;
    for(int i=1;i<=n;i++){
            if(a[i]<b[i]){
                          printf("%d\n",a[i]);
                          break;
            }
    }
    for(int i=1;i<n-1;i++)scanf("%d",a+i);
    sort(a+1,a+n-1);
    a[n-1]=2147483640;
    for(int i=1;i<=n-1;i++){
            if(a[i]>b[i]){
                          printf("%d\n",b[i]);
                          break;
            }
    }       
	//system("pause");
	return 0;
}