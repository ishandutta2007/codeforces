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
int n,k,q,f[1000005],cnt[1000005];
ll ans,ny[200005],g[200005],h[1000005];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	ny[0]=ny[1]=1;
	for(int i=2;i<=n+q;++i)ny[i]=((orz-orz/i)*ny[orz%i])%orz;
	for(int i=k+1;i<=n+q;++i)g[i]=i*ny[i-k]%orz;
	for(int i=1;i<=1000000;++i)f[i]=i;
	for(int i=1;i<=1000000;++i){
		for(int j=i+i;j<=1000000;j+=i)f[j]-=f[i];
	}
	for(int i=1;i<=n+q;++i){
		int x;
		scanf("%d",&x);
		for(int j=1;j*j<=x;++j){
			if(x%j) continue;
			++cnt[j];
			if(cnt[j]==k)h[j]=1,(ans+=f[j])%=orz;
			else if(cnt[j]>k){
				ll o=h[j]*g[cnt[j]]%orz;
				(ans+=((o-h[j])*f[j]))%=orz;
				h[j]=o;
			}
			if(j*j!=x){
				j=x/j;
				++cnt[j];
				if(cnt[j]==k)h[j]=1,(ans+=f[j])%=orz;
				else if(cnt[j]>k){
					ll o=h[j]*g[cnt[j]]%orz;
					(ans+=((o-h[j])*f[j]))%=orz;
					h[j]=o;
				}
				j=x/j;
			}
		}
		ans=(ans%orz+orz)%orz;
		if(i>n)printf("%I64d\n",ans);
	}
    return 0;
}