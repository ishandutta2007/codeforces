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
//:
using namespace std;
int n,m,a[1005],d[305],l,r,k,x[1000005],y[1000005],s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",d+i);
    m=d[n]+1;
    l=1,r=n,k=1;
    for(int i=m;i;--i){
        if(a[k]+1>d[l])--r,++l;
        if(d[r]<=a[i]) break;
        k=i-d[r]+a[i];
        for(int j=k;j<i;++j)x[++s]=j,y[s]=i,++a[j];
    }
    printf("%d\n",s);
    for(int i=1;i<=s;++i)printf("%d %d\n",x[i],y[i]);
	//system("pause");
	return 0;
}