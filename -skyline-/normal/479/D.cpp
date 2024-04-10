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
int n,l,x,y,a[100005];
set<int> s1,s2;
int main()
{
    scanf("%d%d%d%d",&n,&l,&x,&y);
    for(int i=1;i<=n;i++){
            int xx;
            scanf("%d",&xx);
            s1.insert(xx);
            a[i]=xx;
    }
    bool kx=0,ky=0;
    for(int i=1;i<=n;i++){
            if(s1.count(a[i]-x)||s1.count(a[i]+x))kx=1;
            if(s1.count(a[i]-y)||s1.count(a[i]-y))ky=1;
            if(a[i]-x>=0)s2.insert(a[i]-x);
            if(a[i]+x<=l)s2.insert(a[i]+x);
    }
    if(kx&&ky){
               puts("0");
               return 0;
    }
    if(kx|ky){
              puts("1");
              if(kx)printf("%d\n",y);
              else printf("%d\n",x);
              return 0;
    }
    for(int i=1;i<=n;i++){
            if(s2.count(a[i]-y)){
                                 puts("1");
                                 printf("%d\n",a[i]-y);
                                 return 0;
            }
            if(s2.count(a[i]+y)){
                                 puts("1");
                                 printf("%d\n",a[i]+y);
                                 return 0;
            }                     
    }
    puts("2");
    printf("%d %d\n",x,y);                                   
	//system("pause");
	return 0;
}