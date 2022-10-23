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
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
ll t[262199],n,a[100005],res[100005],p,q;
ll ans;
ll cty(ll l,ll r,ll k){
    if(p>r||q<l) return 0;
    if(p<=l&&r<=q) return t[k];
    ll m=(l+r)>>1,x,y;
    x=cty(l,m,k<<1);
    y=cty(m+1,r,(k<<1)^1);
    return a[x]>a[y]?x:y;
}
int main()
{
    scanf("%I64d",&n);
    for(ll i=1;i<n;i++)scanf("%I64d",a+i),t[i+131071]=i;
    a[n]=n,t[n+131071]=n;
    for(ll i=131071;i;i--){
            ll l=i<<1,r=l^1;
            t[i]=a[t[l]]>a[t[r]]?t[l]:t[r];
    }
    for(ll i=n-1;i;i--){
            p=i,q=a[i];
            ll x=cty(1,131072,1);
            res[i]=res[x]+n+x-i-a[i];
            ans+=res[i];
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}