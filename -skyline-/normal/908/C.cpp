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
//:
using namespace std;
int n,r,x[1005];
double d[1005];
double calc(int p,int q){
    int k=abs(x[p]-x[q]);
    if(k>2*r) return 0;
    double d1=r*4.0*r,d2=k*1.0*k;
    double d3=d1-d2;
    d3=sqrt(d3);
    return d3+d[q];
}
int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++)scanf("%d",x+i);
    for(int i=1;i<=n;i++){
        d[i]=r;
        for(int j=1;j<i;j++)d[i]=max(d[i],calc(i,j));
    }
    for(int i=1;i<n;i++)printf("%.10lf ",d[i]);
    printf("%.10lf\n",d[n]);
//	system("pause");
	return 0;
}