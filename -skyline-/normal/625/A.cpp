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
ll n,a,b,c,ans;
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    ans=max(ans,n/a);
    ll u=n-ans*a;
    ans+=(u>=b?1+(u-b)/(b-c):0);
    if(n>=b){
             ll res=1;
             n-=b;
             ll o=(n/(b-c));
             if(o>10)o-=10;
             n-=o*(b-c);
             res+=o;
             for(ll i=1;i<=20;i++){
                    if(n<0) break;
                    ans=max(ans,res+((n+c)/a));
                    if(n>=(b-c)){
                                n-=b-c;
                                res++;
                    }
             }
    }
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}