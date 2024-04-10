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
#define LL         long long   
using namespace std;
long long a,b,c,l,r,m;
int main()
{
    long long cnt1,cnt2,x,y;
    long long i,j,k;
    cin>>cnt1>>cnt2>>x>>y;
    l=0;
    r=500*1000*1000*1000*1000LL;
    cnt1*=1LL;
    cnt2*=1LL;
    x*=1LL;
    y*=1LL;
    while(r-l>1){
                 m=(l+r)*1LL/2LL;
                 a=m/x;
                 a=m-a;   
                 a=a*1LL;
                 b=m/y;
                 b=m-b;
                 b=b*1LL;
                 c=m/(x*y);
                 c=m-c;
                 c=c*1LL;
                 c=a+b-c;
                 c=c*1LL;
                 if((a+b-c>=cnt1+cnt2)&&(a>=cnt1)&&(b>=cnt2))r=m;
                 else l=m;
    }
    cout<<r<<endl;   
	return 0;
}