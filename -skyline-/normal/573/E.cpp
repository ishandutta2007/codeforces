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
ll ans,s[100005],a[100005],n;
bool b[100005];
int main()
{
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",a+i),b[i]=1,ans+=a[i]*i,s[i]=s[i-1]+a[i];
    while(1){
             bool c=0;
             ll o=1,p=0;
             for(int j=1;j<=n;j++){
                     if(b[j]&&a[j]*o+s[n]-s[j]<0)b[j]=0,c=1;
                     if(!b[j]&&a[j]*o+s[n]-s[j]>=0)b[j]=1,c=1;
                     if(b[j])s[j]=s[j-1]+a[j],p+=(o++)*a[j];
                     else s[j]=s[j-1];
             }
             ans=max(ans,p);
             if(!c) break;
    }
    printf("%I64d\n",ans);                
//	system("pause");
	return 0;
}