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
int n,m;
bool cty(int k){
    int a2,a3,a6;
    a6=k/6;
    a2=k/2;
    a3=k/3;
    a2-=a6;
    a3-=a6;
    if(a3<m)a6-=m-a3;
    if(a6<0) return 0;
    if(a2+a6<n) return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    int l=1,r=6000000;
    while(r-l>1){
                 int k=(r+l)>>1;
                 if(cty(k))r=k;
                 else l=k;
    }
    int k=l;
    while(cty(k-1))k--;
    while(!cty(k))k++;
    printf("%d\n",k);
	//system("pause");
	return 0;
}