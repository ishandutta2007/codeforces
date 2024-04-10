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
int n,p,q,x,y;
char c[200];
int main()
{
    scanf("%d%d%d",&n,&p,&q);
    for(int i=1;i<=n;i++)scanf(" %c",c+i);
    for(;x<=101;x++){
                     for(y=0;y<=101;y++){
                                      if(x*p+y*q==n){
                                                     int t=0;
                                                     printf("%d\n",x+y);
                                                     for(int i=1;i<=x;i++){
                                                             for(int j=1;j<=p;j++)printf("%c",c[++t]);
                                                             printf("\n");
                                                     }
                                                     for(int i=1;i<=y;i++){
                                                             for(int j=1;j<=q;j++)printf("%c",c[++t]);
                                                             printf("\n");
                                                     }
                                                     return 0;
                                      }
                     }
    }
    puts("-1");                                                         
  //  system("pause");
    return 0;
}