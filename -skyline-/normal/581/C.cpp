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
int n,k,ans,a[20];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            ans+=(int)(x/10);
            a[10-x%10]++;
    }
    for(int i=1;i<=9;i++){
            if(!k) break;
            int u=min(k/i,a[i]);
            k-=u*i;
            ans+=u;
    }
    ans+=(int)(k/10);
    if(ans>n*10)ans=n*10;
    printf("%d\n",ans);
  //  system("pause");
    return 0;
}