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
using namespace std;
long long n,a[200005],f[200005],fs,s[200005],ss;
int main()
{
    scanf("%I64d",&n);
    for(long long i=1;i<=n;i++){
             scanf("%I64d",a+i);
             if(a[i]>0)fs++,f[fs]=a[i],f[0]+=a[i];
             else ss++,s[ss]=-a[i],s[0]-=a[i];
    }
    for(long long i=0;i<=min(ss,fs);i++)
             if(f[i]!=s[i]){
                            puts(f[i]>s[i]?"first":"second");
                            return 0;
             }
    puts(a[n]>0?"first":"second");                               
	//system("pause");
	return 0;
}