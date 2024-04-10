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
int n,m,ans=2147483640,x[4005],y[4005],s[4005];
bool b[4005][4005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            scanf("%d%d",x+i,y+i);
            b[x[i]][y[i]]=b[y[i]][x[i]]=1;
            s[x[i]]++,s[y[i]]++;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(b[x[j]][i]&&b[y[j]][i])ans=min(ans,s[x[j]]+s[y[j]]+s[i]);
            }
    }
    if(ans==2147483640)ans=5;
    printf("%d\n",ans-6);
 //   system("pause");
    return 0;
}