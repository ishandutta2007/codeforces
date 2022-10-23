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
int n;
int main()
{
    scanf("%d",&n);
    if(n==1)printf("YES\n2 1\n1 2\n");
    else if(n%2==0)printf("NO\n");
    else{
         printf("YES\n%d %d\n",2*n+4,n*n+2*n);
         printf("1 %d\n%d %d\n%d %d\n",n+3,n+1,n+2,2*n+3,2*n+4);
         for(int i=2;i<=n;i++){
                 printf("1 %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i,i,n+1,i,n+2,n+3,n+2+i,n+2+i,2*n+3,n+2+i,2*n+4);
                 for(int j=i+1;j<=n;j++){
                         if(j==(int)(i+n/2)) continue;
                         printf("%d %d\n%d %d\n",i,j,i+n+2,j+n+2);
                 }
         }
    }
   // system("pause");
    return 0;
}