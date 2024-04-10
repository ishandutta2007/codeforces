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
int n,a[1005],b[1005],ok=2;
double m,M;
int main(){
    cin>>n>>m;
    M=m;
    for(int i=1;i<=n;++i)cin>>a[i],ok=min(ok,a[i]);
    for(int i=1;i<=n;++i)cin>>b[i],ok=min(ok,b[i]);
    if(ok<=1){
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;++i)m=m/(a[i]-1.0)*(a[i]*1.0);
    for(int i=1;i<=n;++i)m=m/(b[i]-1.0)*(b[i]*1.0);
    printf("%.10lf\n",m-M);
//	system("pause");
	return 0;
}