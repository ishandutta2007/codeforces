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
#include<Windows.h>
using namespace std;
long long n,m,k,p,a[1006][1006],ans=-999999999999991,ll,rr[1000001],cc[1000001];
priority_queue<long long> r,c;
 
int main()
{
    long long i,j,l;
    cin>>n>>m>>k>>p;
    for(i=1;i<=n;i++){
                      for(j=1;j<=m;j++)cin>>a[i][j];
    }
    for(i=1;i<=n;i++){
                      l=0;
                      for(j=1;j<=m;j++)l+=a[i][j];
                      r.push(l);
    }
    for(j=1;j<=m;j++){
                      l=0;
                      for(i=1;i<=n;i++)l+=a[i][j];
                      c.push(l);
    }
    long long s=0;
    for(i=1;i<=k;i++){
                       long long t=r.top();
                       s+=t;
                       rr[i]=s;                   
                       r.pop();
                                        
                       r.push(t-m*p);
    }
    s=0;
    for(i=1;i<=k;i++){
                         long long t=c.top();
                         s+=t;
                         cc[i]=s;
                         c.pop();
                         c.push(t-n*p);
    }
    for(ll=0;ll<=k;ll++){
                         long long ss;
                      ss=rr[ll]+cc[k-ll];   
                      ss-=ll*(k-ll)*p;
                      ans=max(ans,ss);
    }
    printf("%I64d\n",ans);                                      
                                                                                             
   //system("pause");
    return 0;
}