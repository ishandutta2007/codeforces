//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#define orz  1000000007
//:
using namespace std;
int n,m,c,a[1005],l,r,o,x;
void out(int k){
     printf("%d\n",k);
     fflush(stdout);
     a[k]=x;
}
int main()
{
    scanf("%d%d%d",&n,&m,&c);
    r=n+1;
    o=c/2;
    for(int i=1;i<=m;i++){
            if(l==r-1) break;
            scanf("%d",&x);
            if(x<=o){
                     if(l==0||a[l]<=x)out(++l);
                     else{
                          for(int j=1;j<=l;j++){
                                  if(a[j]>x){
                                             out(j);
                                             break;
                                  }
                          }
                     }
            }
            else{
                 if(r==n+1||a[r]>=x)out(--r);
                 else{
                      for(int j=n;j>=r;j--){
                              if(a[j]<x){
                                         out(j);
                                         break;
                              }
                      }
                 }
            }
            if(l==r-1) break;
    }
//	system("pause");
	return 0;
}