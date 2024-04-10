//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n;
ll r1,r2,r3,d,a[2000005],dp[2000005][2],ans=orz*1ll*orz,x,y,s[2000005];
int main(){
	scanf("%d%I64d%I64d%I64d%I64d",&n,&r1,&r2,&r3,&d);
	for(int i=1;i<=n;++i)scanf("%I64d",a+i),s[i]=min(a[i]*r1+r3,min(r1*(a[i]+2),r1+r2));
	s[n]=min(a[n]*r1+r3,min(r1*(a[n]+2),r1+r2)+d*2);
	for(int i=n;i>=1;--i)s[i]=min(s[i+1]+s[i],ans);
	dp[0][1]=ans;
	for(int i=1;i<=n;++i){
		x=a[i]*r1+r3;
		y=min(r1+r2,r1*(a[i]+2));
		dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]+d*2)+x,dp[i-1][1]+y+d*2);
		dp[i][1]=dp[i-1][0]+y;
		if(i<n)ans=min(ans,dp[i][1]+s[i+1]+(n-i)*d);
		else ans=min(ans,dp[i][1]+s[i+1]+2*d);
	}
	ans=min(ans,dp[n][0]);
	printf("%I64d\n",ans+d*(n-1));
    return 0;
}