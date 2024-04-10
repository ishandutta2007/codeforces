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
ll n,m,k,p[2005],res;
ll ope(ll x){return x==p[x]?x:p[x]=ope(p[x]);};
ll fpower(ll x,ll k){
    ll ans=1;
    while(k){
             if(k&1) ans=(ans*x)%1000000007;
             k>>=1;
             x=(ll)(x*x)%1000000007;
    }
    return ans;
}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    for(ll i=1;i<=n;i++)p[i]=i;
    for(ll i=1;i<=n-k+1;i++){
            for(ll j=0;j<k/2;j++)if(ope(i+j)!=ope(i+k-1-j))p[p[i+j]]=p[i+k-1-j];
    }
    for(ll i=1;i<=n;i++)res+=(p[i]==i);
    printf("%I64d\n",fpower(m,res));
    //system("pause");
    return 0;
}