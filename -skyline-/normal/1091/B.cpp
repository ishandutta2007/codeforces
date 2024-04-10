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
using namespace std;
int n,x[1005],y[1005],a[1005],b[1005];
set<pair<int,int> >s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",x+i,y+i),s.insert(mp(x[i],y[i]));
    for(int i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
    for(int i=1;i<=n;++i){
        int X=x[1]+a[i],Y=y[1]+b[i];
        bool ok=1;
        for(int j=2;j<=n;++j)if(!s.count(mp(X-a[j],Y-b[j])))ok=0,j=n;
        if(ok){
            printf("%d %d\n",X,Y);
            break;
        }
    }
	//system("pause");
	return 0;
}