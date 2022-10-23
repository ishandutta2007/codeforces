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
int n,ans=1;
char c[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf(" %c",c+i);
    for(int i=2;i<=n;i++)if(c[i]!=c[i-1])ans++;
    int t;
    c[n+1]='*';
    for(t=1;t<=n;t++)if(c[t]==c[t+1]) break;
    if(c[t]==c[t+1]){
                     for(t=t+1;t<=n;t++)if(c[t]==c[t+1]) break;
                     if(c[t]==c[t+1]) ans+=2;
                     else ans++;
    }
    printf("%d\n",ans);
   // system("pause");
    return 0;
}