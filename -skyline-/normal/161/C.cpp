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
int p1,p2,q1,q2;
int ope(int o,int a,int b,int c,int d){
    if(!o||a>b||c>d) return 0;
    if(a>c||(a==c&&b>d)) return ope(o,c,d,a,b);
    if(d<=b) return d-c+1;
    if(a==c) return b-a+1;
    int k=(1<<o)>>1;
    if(d<k) return ope(o-1,a,b,c,d);
    if(a>k) return ope(o-1,a-k,b-k,c-k,d-k);
    if(b<k&&c>k) return ope(o-1,a,b,c-k,d-k);
    if(b<k) return max(ope(o-1,a,b,c,k-1),ope(o-1,a,b,1,d-k));
    if(c>k) return max(ope(o-1,a,k-1,c-k,d-k),ope(o-1,1,b-k,c-k,d-k));
    return max(min(b,d)-c+1,max(ope(o-1,a,k-1,1,d-k),ope(o-1,c,k-1,1,b-k)));
}
int main()
{
    scanf("%d%d%d%d",&p1,&p2,&q1,&q2);
    printf("%d\n",ope(30,p1,p2,q1,q2));
	//system("pause");  
	return 0;
}