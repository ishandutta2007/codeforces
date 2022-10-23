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
int n,x[100005],y[100005],cnt;
double d,o;
bool ok(double d){
    double l=-20000000.0,r=20000000.0;
    for(int i=1;i<=n;++i){
        double p=y[i]*1.0-d;
        if(p<0)p=-p;
        if(p>d) return 0;
        p=sqrt(d+p)*sqrt(d-p);
        double X=x[i]*1.0;
        if(l<X-p)l=X-p;
        if(r>X+p)r=X+p;
    }
    return l<=r;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",x+i,y+i);
        if(y[i]<0) ++cnt;
    }
    if(cnt&&cnt<n){
        puts("-1");
        return 0;
    }
    if(cnt==n){
        for(int i=1;i<=n;++i)y[i]=-y[i];
    }
    d=o=(double)(1ll<<50);
    for(int _=1;_<=80;++_){
        d/=2.0;
        if(ok(o-d))o-=d;
    }
    printf("%.10lf\n",o);
//	system("pause");
	return 0;
}