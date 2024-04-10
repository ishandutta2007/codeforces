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
int a1,a2,b1,b2,c1,c2,n;
int main()
{
    scanf("%d%d%d%d%d%d",&a1,&a2,&b1,&b2,&c1,&c2);
    if(a1>a2)swap(a1,a2);
    if(b1>b2)swap(b1,b2);
    if(c1>c2)swap(c1,c2);
    n=a1*a2+b1*b2+c1*c2;
    for(int i=1;i<=200;i++){
            if(i*i==n){
                       n=-i;
                       break;
            }
    }
    if(n>0){
            printf("-1\n");
            return 0;
    }
    n=-n;
    if(a2!=n&&b2!=n&&c2!=n){
                            printf("-1\n");
                            return 0;
    }
    if((a2==n)+(b2==n)+(c2==n)==2){
                                   printf("-1\n");
                                   return 0;
    }
    if((a2==n)+(b2==n)+(c2==n)==3){
                                   printf("%d\n",n);
                                   for(int i=1;i<=n;i++){
                                           for(int j=1;j<=a1;j++)printf("A");
                                           for(int j=1;j<=b1;j++)printf("B");
                                           for(int j=1;j<=c1;j++)printf("C");
                                           printf("\n");
                                   }
                                   return 0;
    }
    if(a2==n){
              int m=n-a1;
              if(b1!=m&&b2!=m){
                               printf("-1\n");
                               return 0;
              }
              if(c1!=m&&c2!=m){
                               printf("-1\n");
                               return 0;
              }
              if(b1!=m)swap(b1,b2);
              if(c1!=m)swap(c1,c2);
              printf("%d\n",n);
              for(int i=1;i<=b2;i++){
                      for(int i=1;i<=a1;i++)printf("A");
                      for(int i=1;i<=m;i++)printf("B"); 
                      printf("\n");
              }
              for(int i=1;i<=c2;i++){
                      for(int i=1;i<=a1;i++)printf("A");
                      for(int i=1;i<=m;i++)printf("C");
                      printf("\n");
              }
    }
    if(b2==n){
              int m=n-b1;
              if(a1!=m&&a2!=m){
                               printf("-1\n");
                               return 0;
              }
              if(c1!=m&&c2!=m){
                               printf("-1\n");
                               return 0;
              }
              if(a1!=m)swap(a1,a2);
              if(c1!=m)swap(c1,c2);
              printf("%d\n",n);
              for(int i=1;i<=a2;i++){
                      for(int i=1;i<=b1;i++)printf("B");
                      for(int i=1;i<=m;i++)printf("A");
                      printf("\n");
              }
              for(int i=1;i<=c2;i++){
                      for(int i=1;i<=b1;i++)printf("B");
                      for(int i=1;i<=m;i++)printf("C");
                      printf("\n");
              }
    }
    if(c2==n){
              int m=n-c1;
              if(b1!=m&&b2!=m){
                               printf("-1\n");
                               return 0;
              }
              if(a1!=m&&a2!=m){
                               printf("-1\n");
                               return 0;
              }
              if(b1!=m)swap(b1,b2);
              if(a1!=m)swap(a1,a2);
              printf("%d\n",n);
              for(int i=1;i<=b2;i++){
                      for(int i=1;i<=c1;i++)printf("C");
                      for(int i=1;i<=m;i++)printf("B");  
                      printf("\n");
              }
              for(int i=1;i<=a2;i++){
                      for(int i=1;i<=c1;i++)printf("C");
                      for(int i=1;i<=m;i++)printf("A"); 
                      printf("\n");
              }
    }
  //  system("pause");
    return 0;
}