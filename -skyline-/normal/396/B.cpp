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
typedef long long LL;
inline long long gcd(long long a,long long b)
{
    return(b==0?a:gcd(b,a%b));
}


bool prime(long long n)
{
 	 long long i=9;
 	 if(n>1)
 	 {
	  		for(i=2;i<=sqrt(n);i++)
	  		{
                 if(n%i==0)
                     i=n+4;
            }
     }
     i-=1;
	 if(i<n)
	     return true;
	 else
	     return false;
}	 				 
int main()
{
 	long long a,m,n,i,cs,p,q;
 	cin>>cs;
 	for(i=1;i<=cs;i++){
					   cin>>a;
					   m=a;
					   n=a+1;
					   while(prime(m)==0)m--;
					   while(prime(n)==0)n++;
					   if(a==n-1)p=n-2,q=2*n;
					   else p=(m*n)+2LL*(a-m-n+1LL),q=2LL*m*n;
					   long long d=gcd(p,q);
					   p=p/d;
					   q=q/d;
					   cout<<p<<'/'<<q<<endl;
    }
					   
	//system("pause");
	return 0;
}