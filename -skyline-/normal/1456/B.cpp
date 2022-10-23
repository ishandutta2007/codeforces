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
int n,a[100005],f[2][30][100005];
int ans=orz;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i),a[i]^=a[i-1];
	for(int i=0;i<2;++i){
		for(int j=0;j<30;++j)f[i][j][0]=-i;
	}
	for(int i=0;i<2;++i){
		for(int j=0;j<30;++j){
			for(int k=1;k<=n;++k){
				if(((a[k]>>j)&1)==i)f[i][j][k]=k;
				else f[i][j][k]=f[i][j][k-1];
			}
		}
	}
	for(int i=1;i<=n;++i){
		int o=i;
		for(int j=29;j>=0;--j){
			o=min(o,f[(a[i]>>j)&1][j][i-1]);
			if(o<0) break;
			int p=f[((a[i]>>j)&1)^1][j][o];
			if(p>=0)ans=min(ans,i-p);
		}
	}
	if(ans==orz)ans=1;
	printf("%d\n",ans-2);
    return 0;
}