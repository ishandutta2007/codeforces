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
int n,ans[505],a[150005],s;
map<int,int> m;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    int x;
                    scanf("%d",&x);
                    m[x]++;
                    if(m[x]==1)a[++s]=x;
            }
    }
    sort(a+1,a+s+1);
    for(int i=1;i<=n;i++){              
            while(!m[a[s]])s--;
            ans[i]=a[s];
            m[a[s]]--;
            for(int j=1;j<i;j++)m[__gcd(ans[i],ans[j])]-=2;
    }
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
   // system("pause");
    return 0;
}