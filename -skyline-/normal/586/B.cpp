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
int n,a1[55],a2[55],b[55],ans1=999999999,ans2=999999999;
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
            scanf("%d",a1+i);
            a1[i]+=a1[i-1];
    }
    for(int i=1;i<n;i++)scanf("%d",a2+i);
    for(int i=1;i<=n;i++)scanf("%d",b+i);
    for(int i=n-1;i;i--)a2[i]+=a2[i+1];
    for(int i=1;i<=n;i++){
            int k=a1[i]+b[i]+a2[i];
            if(k<=ans1)ans2=ans1,ans1=k;
            else if(k<ans2)ans2=k;
    }
    printf("%d\n",ans1+ans2);
  //  system("pause");
    return 0;
}