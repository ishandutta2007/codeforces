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
int n,m,x,res,o;
double f[1000005],a[1000005],b[1000005],ans;
void ope(){                  
     o+=m;
     for(int i=1;i<=o;i++)a[i]=a[i-1]+f[i-1];
     for(int i=0;i<=o;i++)b[i]=(a[i]-a[max(0,i-m)]-(i>=x?f[i-x]:0))/(m-1.00000);
     for(int i=0;i<=o;i++)f[i]=b[i];
}
int main()
{
    scanf("%d%d",&n,&m);   
    f[0]=1.0000;
    for(int i=1;i<=n;i++){
            scanf("%d",&x);
            ope();
            res+=x;
    }
    for(int i=n;i<res;i++)ans+=f[i];
    ans*=(m-1);
    printf("%.10lf\n",ans+1.00000);        
   // system("pause");
    return 0;
}