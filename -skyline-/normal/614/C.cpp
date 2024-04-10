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
double x,y,a[100005],b[100005],o=-1,p=1234554.0*3211234*12345;
int n;
int main()
{
    scanf("%d%lf%lf",&n,&x,&y); 
    for(int i=1;i<=n;i++){
            scanf("%lf%lf",a+i,b+i);
            a[i]-=x,b[i]-=y;
            double k=a[i]*a[i]+b[i]*b[i];
            o=max(o,k);
            p=min(p,k);
    }
    a[n+1]=a[1],b[n+1]=b[1];
    for(int i=1;i<=n;i++){
            double X=a[i]*(a[i]-a[i+1])+b[i]*(b[i]-b[i+1]),Y=a[i+1]*(a[i]-a[i+1])+b[i+1]*(b[i]-b[i+1]);
            if(X<0)X=-X,Y=-Y;
            if(Y<0){
                    double d=a[i]*b[i+1]-a[i+1]*b[i],dd=d;
                    d/=((a[i]-a[i+1])*(a[i]-a[i+1])+(b[i]-b[i+1])*(b[i]-b[i+1]));         
                    d*=dd;
                    if(d<0)d=-d;
                    p=min(p,d);
            }
    }
    printf("%.15lf\n",double((o-p)*3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647));
   // system("pause");
    return 0;
}