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
int m[10],w[10],hs,hu,ans;
int main()
{
    for(int i=1;i<=5;i++)scanf("%d",m+i);
    for(int i=1;i<=5;i++)scanf("%d",w+i);
    scanf("%d%d",&hs,&hu);
    ans=hs*100-50*hu;
    for(int i=1;i<=5;i++){
            int res=0;
            res=max(150*i,(250-m[i])*2*i-50*w[i]);
            ans+=res;
    }
    printf("%d\n",ans);
 //   system("pause");
    return 0;
}