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
using namespace std;
double a,v,l,d,w;
double Q(){
    if((v-w)/a*(v+w)/2.0+v*v/a/2.0>=l-d){
        double x=sqrt(a*(l-d)+w*w/2.0);
        return (x*2.0-w)/a;
    }
    return (v*2.0-w)/a+(l-d-(v-w)/a*(v+w)/2.0-v*v/a/2.0)/v;
}
double H(){
    if((v-w)/a*(v+w)/2.0>=d){
        double x=sqrt(2.0*a*d+w*w);
        return (x-w)/a;
    }
    return (v-w)/a+(d-(v-w)/a*(v+w)/2.0)/v;
}
int main(){
    cin>>a>>v>>l>>d>>w;
    d=l-d;
    if(w>v)w=v;
    if(w*w/a/2.0>=l-d){
        if(v*v/a/2.0>=l)printf("%.10lf\n",sqrt(l*2.0/a));
        else printf("%.10lf\n",v/a+(l-v*v/a/2.0)/v);
    }
    else{
        printf("%.10lf\n",Q()+H());
    }
//	system("pause");
	return 0;
}