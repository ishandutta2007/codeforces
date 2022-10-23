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
int t,n,p,k,x,y,ans,a[100005],cnt[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&p,&k);
		for(int i=0;i<k;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)scanf("%1d",a+i);
		scanf("%d%d",&x,&y);
		for(int i=p;i<=n;++i)if(!a[i])++cnt[i%k];
		ans=orz*2;
		for(int i=p;i<=n;++i){
			ans=min(ans,(i-p)*y+cnt[i%k]*x);
			if(!a[i])--cnt[i%k];
		}
		printf("%d\n",ans);
	}
    return 0;
}