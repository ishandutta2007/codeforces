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
using namespace std;
int m,n,a[40],l,r;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i){
        printf("1\n");
        fflush(stdout);
        scanf("%d",a+i);
        if(!a[i]) return 0;
    }
    l=1,r=m;
    int i=0;
    while(l<=r){
        ++i;
        if(i>n)i-=n;
        int k=(l+r)>>1;
        printf("%d\n",k);
        fflush(stdout);
        int o;
        scanf("%d",&o);
        if(!o) return 0;
        if(o==a[i])l=k+1;
        else r=k-1;
    }
//	system("pause");
	return 0;
}