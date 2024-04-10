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
ll n,m,ans,x=1000000007,k;       
int main()
{
    scanf("%I64d%I64d",&n,&m);
    if(m>n){
            ans=((m-n)%x*(n%x))%x;
            m=n;
    }
    while(m>5000000){
                     ll l=n/(n/m+1)+1;
                     ans+=(n%m+n%l)%x*((m-l+1)%x)%x*500000004ll%x; 
                     if(ans>=x)ans-=x;
                     m=l-1;
    }
    for(ll i=1;i<=m;i++){
           ans+=n%i;
           if(ans>=x)ans-=x;
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}