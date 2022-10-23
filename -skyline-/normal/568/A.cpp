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
ll p,q,hw,ss,m;
bool b[5000005]={1,1},c[5000005];
int main()
{
    scanf("%I64d%I64d",&p,&q);
    ll pq=__gcd(p,q);
    p/=pq,q/=pq;
    for(ll i=2;i<=2237;i++){
            if(b[i]) continue;
            for(ll j=i+i;j<5000003;j+=i)b[j]=1;
    }
    for(ll i=1;i<=5000001;i++){
            ll t=i,s=0;
            while(t){
                     s=s*10+t%10;
                     t/=10;
            }
            c[i]=(i==s);
    }
    for(ll i=1;i<=5000001;i++){
            if(!b[i])ss+=q;
            if(c[i])hw+=p;
            if(ss<=hw)m=i;
    }
    printf("%I64d\n",m);        
    //system("pause");
    return 0;
}