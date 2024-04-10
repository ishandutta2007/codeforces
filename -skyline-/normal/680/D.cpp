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
ll m,t[100005];
pair<ll,ll> ans;
void cty(ll o,ll x,ll y,ll k){
            if(!o){
                   ans=max(ans,mp(x,y));
                   return;
            }
            while(t[k]>o)k--;
            cty(o-t[k],x+1,y+t[k],k);
            if(k>1)cty(t[k]-1-t[k-1],x+1,y+t[k-1],k);
}
int main()
{
    for(ll i=1;i<=100002;i++)t[i]=i*1ll*i*i;
    scanf("%I64d",&m);
    cty(m,0,0,100000);
    printf("%I64d %I64d\n",ans.first,ans.second);
//	system("pause");
	return 0;
}