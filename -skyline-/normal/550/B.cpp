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
int n,l,r,x,a[20],ans;
bitset<20> b;
int main()
{
    scanf("%d%d%d%d",&n,&l,&r,&x);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    while(b[0]==0){
                   int mn=2147483640,mx=-1,s=0;
                   for(int i=1;i<=n;i++)if(b[i])mx=max(mx,a[i]),mn=min(mn,a[i]),s+=a[i];
                   if(l<=s&&s<=r&&mx-mn>=x)ans++;
                   int i=n;
                   while(b[i])b[i]=0,i--;
                   b[i]=1;
    }
    printf("%d\n",ans);                     
   // system("pause");
    return 0;
}