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
ll n,m,k,o[200005],a[2005];
pair<int,int> p[2005];
long long fpower(long long x,long long k){
     long long ans=1;
     x%=1000000007;
     while(k){
              if(k&1) ans=ans*x%1000000007;
              k>>=1;
              x=x*x%1000000007;
     }
     return ans;
}
ll c(ll x,ll y){
	return o[x]*fpower(o[y]*o[x-y]%1000000007,1000000005)%1000000007;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(int i=1;i<=k;i++)scanf("%I64d%I64d",&p[i].first,&p[i].second);
	sort(p+1,p+k+1);
	p[++k]=make_pair(n,m);
	o[0]=o[1]=1;
	for(int i=2;i<=200005;i++)o[i]=o[i-1]*i%1000000007;
	for(int i=1;i<=k;i++){
		ll x=p[i].first-1,y=p[i].second-1;
		a[i]=c(x+y,x);
		for(int j=1;j<i;j++){
			ll u=p[j].first-1,v=p[j].second-1;
			if(u>x||v>y) continue;
			a[i]-=c(x-u+y-v,x-u)*a[j]%1000000007;
			a[i]=(a[i]+1000000007)%1000000007;
		}
	}
	printf("%I64d\n",a[k]);
	return 0;
}