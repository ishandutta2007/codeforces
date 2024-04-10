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
int n,x,y,z,a[200005],o,X,Y,Z,XY,XZ,YZ;
bool ok(int t){
     X=Y=Z=XY=XZ=YZ=0;
     for(int i=o;i;i--){
             if(X+XY+XZ<t&&a[i]<=x)X++;
             else if(Y+XY+YZ<t&&a[i]<=y)Y++;
             else if(Z+XZ+YZ<t&&a[i]<=z)Z++;
             else if(X+Y+XY+XZ+YZ<t&&a[i]<=x+y)XY++;
             else if(X+Z+XY+XZ+YZ<t&&a[i]<=x+z)XZ++;
             else if(Y+Z+XY+XZ+YZ<t&&a[i]<=y+z)YZ++;
             else return 0;
     }
     return 1;
}
     
     
int main()
{
    scanf("%d%d%d%d",&n,&x,&y,&z);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    if(a[n]>x+y+z){
                   printf("-1\n");
                   return 0;
    }
    if(x>y)swap(x,y);
    if(x>z)swap(x,z);
    if(y>z)swap(y,z);
    o=n;
    while(a[o]>y+z&&o)o--;
    int l=0,r=o+5;
    while(r-l>1){
                 int m=(l+r)>>1;
                 if(ok(m)) r=m;
                 else l=m;
    }
    l-=3;
    while(!ok(l))l++;
    printf("%d\n",n-o+l);
   // system("pause");
    return 0;
}