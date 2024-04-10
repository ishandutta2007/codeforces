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
int n,k;
char a[600][600];
void ope(int n){
     if(n==2){
              a[1][1]=a[1][2]=a[1][3]=a[1][4]=a[2][1]=a[2][2]=a[3][1]=a[3][3]=a[4][2]=a[4][3]='+';
              for(int i=1;i<=n;i++){
                      for(int j=1;j<=n;j++)if(a[i][j]!='+')a[i][j]='*';
              }
              return;
     }
     ope(n-1);
     int t=1<<(n-1);
     for(int i=1;i<=t;i++){
             for(int j=1;j<=t;j++)a[i][j+t]=a[i+t][j]=a[i][j],a[i+t][j+t]=('+')+('*')-a[i][j];
     }
}
int main()
{
    scanf("%d",&n);
    if(n==0)printf("+\n");
    else if(n==1)printf("++\n+*\n");
    else{        
         k=1<<n;
         for(int i=1;i<=k;i++){
                 for(int j=1;j<=k;j++)a[i][j]='*';
         }
         ope(n);
         for(int i=1;i<=k;i++){
                 for(int j=1;j<=k;j++)printf("%c",a[i][j]);
                 printf("\n");
         }
    }
 //   system("pause");
    return 0;
}