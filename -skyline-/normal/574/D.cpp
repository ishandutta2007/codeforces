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
int a[100005],n;
bool ok(int k){
     int p[200005]={};
     p[1]++,p[k+1]--,p[n-k+1]++;
     for(int i=1;i<=n;i++)if(a[i]<=k)p[max(i+a[i]-k,1)]++,p[i-a[i]+k+1]--;
     int s=0;
     for(int i=1;i<=n;i++){
             s+=p[i];
             if(!s) return 1;
     }
     return 0;
}        
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int l=1,r=n;
    while(r>l){
               int m=(l+r)/2;
               if(ok(m))l=m+1;
               else r=m;
    }
    printf("%d\n",l);
  //  system("pause");
    return 0;
}