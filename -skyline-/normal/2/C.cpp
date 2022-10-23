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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
double x[5],y[5],r[5],X,Y,a[5];
double f(double X,double Y){
    for(int i=1;i<=3;++i)a[i]=sqrt((x[i]-X)*(x[i]-X)+(y[i]-Y)*(y[i]-Y))/r[i];
    return (a[1]-a[2])*(a[1]-a[2])+(a[2]-a[3])*(a[2]-a[3])+(a[1]-a[3])*(a[1]-a[3]);
}
int main(){
    for(int i=1;i<=3;++i)scanf("%lf%lf%lf",x+i,y+i,r+i);
    X=(x[1]+x[2]+x[3])/3.0;
    Y=(y[1]+y[2]+y[3])/3.0;
    double d=1.0;
    for(int _=1;_<=900000;++_){
        if(f(X+d,Y)<f(X,Y))X+=d;
        else if(f(X-d,Y)<f(X,Y))X-=d;
        else if(f(X,Y+d)<f(X,Y))Y+=d;
        else if(f(X,Y-d)<f(X,Y))Y-=d;
        else d*=0.8;
    }
    if(f(X,Y)<=0.00001)printf("%.5lf %.5lf\n",X,Y);
//	system("pause");
	return 0;
}