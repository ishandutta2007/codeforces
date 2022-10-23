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
//:
using namespace std;
int n,m,w,a[100005];
bool ok(int k){
     int r[100005]={0},ans=0,nw=0;
     for(int i=1;i<=n;i++){
             if(i>w)nw-=r[i-w];
             if(nw+a[i]>=k) continue;
             r[i]=k-nw-a[i];
             ans+=r[i];
             nw+=r[i];
             if(ans>m) return 0;
     }
     return 1;
}      
             
int main()
{
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int l=1,r=m+a[1],d=0;
    while(r-l>1){
                 d++;
                 if(d>a[1]+m) break;
                 int mm=(l+r)/2;
                 if(ok(mm))l=mm;
                 else r=mm;
    }
    if(ok(r))l=r;
    printf("%d\n",l);             
	//system("pause");
	return 0;
}