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
#define ll       long long
using namespace std;
ll n,m,a[100005];
bool ok(ll k){
     ll b[100005],l=n;
     for(int i=1;i<=n;i++)b[i]=a[i];
     b[0]=-1;
     for(int i=1;i<=m;i++){
                           while(!b[l])l--;
                           ll c=k-l;
                           while(c&&l){
                                       ll mi=min(c,b[l]);
                                       b[l]-=mi;
                                       c-=mi;
                                       while(!b[l])l--;
                           }
                           if(!l) return 1;
     }
     return 0;
}
                           
int main()
{
    scanf("%I64d%I64d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%I64d",a+i);
    ll l=1ll,r=200000ll*200000ll*200000ll;
    while(r-l>1){
                 ll m=(l+r)/2ll;
                 if(ok(m)) r=m;
                 else l=m;
    }
    if(!ok(l))l=r;
    printf("%I64d\n",l);             
	//system("pause");
	return 0;
}