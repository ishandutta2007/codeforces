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
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int c[35],n,l;
ll ans,add;
int main(){
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;i++)scanf("%d",c+i);
    for(int i=1;i<=1000;i++){
        for(int j=0;j<n-1;j++)c[j+1]=min(c[j+1],c[j]*2);
        for(int j=1;j<n;j++)c[j-1]=min(c[j-1],c[j]);
    }
    int p=l/(1<<(n-1));
    add=p*1ll*c[n-1];
    l%=(1<<(n-1));
    for(int i=0;i<n;i++)if(l&(1<<i))ans+=c[i]*1ll;
    for(int i=0;i<n;i++){
        ll o=c[i]*1ll;
        for(int j=i;j<n;j++)if(l&(1<<j))o+=c[j]*1ll;
        ans=min(ans,o);
    }
    printf("%I64d\n",ans+add);
//	system("pause");
	return 0;
}