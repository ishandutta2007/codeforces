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
ll n,a[200005],x,y,k,d,ans,s;
int main()
{
    scanf("%I64d",&n);
    for(ll i=1;i<=n;i++)scanf("%I64d",a+i);
    k=1;
    for(ll i=1;i<=n;i++){
            if(a[i]==-1&&(!y)) continue;
            if(a[i]==-1){
                         s+=d;
                         if(s>0)a[i]=s;
                         else{
                              ans++;
                              x=y=0;
                              k=i;
                         }
                         continue;
            }
            if(!x)x=i;
            else if(!y){
                 d=(a[i]-a[x])/(i-x);
                 if(d*(i-x)!=(a[i]-a[x])){
                                          ans++;
                                          x=i;
                                          k=i;
                 }
                 else if((a[x]-(x-k)*d)<1){
                      ans++;
                      k=x=i;
                 }
                 else{
                      y=i;
                      s=a[y];
                 }
            }
            else{
                 s+=d;
                 if(a[i]!=s){
                             ans++;
                             x=i;
                             k=i;
                             y=0;
                 }
            }
    }
    ans++;
    printf("%I64d\n",ans);                                      
	//system("pause");
	return 0;
}