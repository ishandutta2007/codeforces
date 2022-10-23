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
#define ll  long long
//:
using namespace std;
ll n,t=0ll,k=0ll,x,y;
int main()
{
    scanf("%I64d",&n);
    if(n==0){
             printf("0 0\n");
             return 0;
    }
    k = 4ll*n+3ll;
    k/=3;
    k =(ll) sqrt((long double)k);
    k-=1;
    k/=2;
    k++;
    ll i=k;
    n-=3ll*k*(k-1);
    n--;
    x=i+i-1ll;
    y=2ll;
    
    if(n<0){
            printf("%I64d %I64d\n",x-1ll,y-2ll);
            return 0;
    }
    if(n<k){
            x-=n;
            y+=n+n;
            printf("%I64d %I64d\n",x,y);
            return 0;
    }
    x-=k;
    x++;
    y+=k+k;
    y-=2ll;
    n++;
    n-=k;
    if(n<k){
            x-=n+n;
            printf("%I64d %I64d\n",x,y);
            return 0;
    }
    x-=k+k;  
    n-=k;
    if(n<k){
            x-=n;
            y-=n+n;
            printf("%I64d %I64d\n",x,y); 
            return 0;
    }
    x-=k;
    y-=k+k;  
    n-=k;
    if(n<k){
            x+=n;
            y-=n+n;
            printf("%I64d %I64d\n",x,y); 
            return 0;
    }
    x+=k;
    y-=k+k; 
    n-=k;        
    if(n<k){
            x+=n+n;
            printf("%I64d %I64d\n",x,y);
            return 0;
    }
    x+=k+k;   
    n-=k;
    x+=n;
    y+=n+n;
    printf("%I64d %I64d\n",x,y);
   // system("pause");
    return 0;
}