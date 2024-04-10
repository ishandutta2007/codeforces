//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define eps  0.001
#define pi   3.1415926535897932384626433832795
using namespace std;
double x[4],y[4],X,Y,a[4];
bool eq(double x,double y){return x+eps>y&&x-eps<y;}
bool ok(double x,int n){return eq(0,sin(x*n/2.0));}
int main(){
    for(int i=1;i<=3;++i)cin>>x[i]>>y[i];
    while(eq((y[3]-y[1])*(x[2]-x[1]),(x[3]-x[1])*(y[2]-y[1]))){
        x[0]=x[1],x[1]=x[2],x[2]=x[3],x[3]=x[0];
        y[0]=y[1],y[1]=y[2],y[2]=y[3],y[3]=y[0];
    }
    double A=2.0*(x[2]-x[1]),B=2.0*(y[2]-y[1]),C=x[1]*x[1]+y[1]*y[1]-x[2]*x[2]-y[2]*y[2];
    double D=2.0*(x[3]-x[1]),E=2.0*(y[3]-y[1]),F=x[1]*x[1]+y[1]*y[1]-x[3]*x[3]-y[3]*y[3];
    X=(F*B-C*E)/(A*E-D*B);
    Y=(A*F-D*C)/(B*D-A*E);
    for(int i=1;i<=3;++i)a[i]=atan2(y[i]-Y,x[i]-X);
    int n=3;
    while(!ok(a[1]-a[2],n)||!ok(a[1]-a[3],n)||!ok(a[3]-a[2],n))++n;
    printf("%.10lf\n",((x[1]-X)*(x[1]-X)+(y[1]-Y)*(y[1]-Y))*sin(pi*2.0/n)*n/2.0);
//	system("pause");
	return 0;
}