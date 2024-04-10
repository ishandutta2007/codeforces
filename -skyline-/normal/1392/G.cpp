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
int n,m,k,a[22],b[22],l[1000005],r[1000005],p[22],f[1000005],dp[1048666],dp2[1048666];
void u(int &x,int y){if(x>y)x=y;}
void U(int &x,int y){if(x<y)x=y;}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;++i)scanf("%1d",a+i);
    for(int i=0;i<k;++i)scanf("%1d",b+i);
    for(int i=1;i<=n;++i)scanf("%d%d",l+i,r+i),--l[i],--r[i];
    for(int i=0;i<k;++i)p[i]=i;
    for(int i=0;i<(1<<k);++i)dp[i]=n+1;
    int o=0;
    for(int i=n;i;--i){
        swap(p[l[i]],p[r[i]]);
        o=0;
        for(int i=0;i<k;++i)if(a[i])o^=(1<<p[i]);
        dp[o]=i;
        o=0;
        for(int i=0;i<k;++i)if(b[i])o^=(1<<p[i]);
        if(!dp2[o])dp2[o]=i;
    }
    o=0;
    for(int i=0;i<k;++i)if(b[i])o^=(1<<i);
    dp2[o]=n+1;
    for(int _=k;_>=0;--_){ 
	    for(int i=(1<<k)-1;i>=0;--i){
	    	if(__builtin_popcount(i)!=_) continue;
	    	if(dp2[i]>=dp[i]+m){
	    		int ans=k;
	    		for(int j=0;j<k;++j)ans+=((i>>j)&1)*2-a[j]-b[j];
	    		printf("%d\n%d %d\n",ans,dp[i],dp2[i]-1);
	    		return 0;
	    	}
	    	for(int j=0;j<k;++j){
	    		if(i&(1<<j)){
	    			u(dp[i^(1<<j)],dp[i]);
	    			U(dp2[i^(1<<j)],dp2[i]);
	    		}
	    	}
	    }
	}
    return 0;
}