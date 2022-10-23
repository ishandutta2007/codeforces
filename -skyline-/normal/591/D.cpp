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
double sx,sy,ex,ey,v,t,wx1,wy1,wx2,wy2;
bool ok(double z){
     double x=wx1*min(t,z)+wx2*max(0.00,z-t),y=wy1*min(t,z)+wy2*max(0.00,z-t);
     if((ex-x)*(ex-x)+(ey-y)*(ey-y)>v*v*z*z) return 0;
     return 1;
}
int main()
{
    scanf("%lf%lf%lf%lf",&sx,&sy,&ex,&ey),ex-=sx,ey-=sy;
    scanf("%lf%lf%lf%lf%lf%lf",&v,&t,&wx1,&wy1,&wx2,&wy2);
    double l=0,r=100000.0*100000.00;
    for(int i=1;i<=1000000;i++){
            double m=(l+r)/2;
            if(ok(m))r=m;
            else l=m;
    }
    printf("%.10lf\n",l);       
	//system("pause");
	return 0;
}