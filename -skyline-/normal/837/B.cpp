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
//:
using namespace std;
//
//
int f[200],k,a[105][105];
int n,m,ok=3;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    char c;
                    scanf(" %c",&c);
                    if(f[c])a[i][j]=f[c];
                    else a[i][j]=f[c]=++k;
            }
    }
    if(n%3)ok&=1;
    if(m%3)ok&=2;
    for(int i=1;i<=n/3;i++){
            for(int j=1;j<=m;j++)if(a[i][j]!=1)ok&=1;
    }
    for(int i=(n/3)+1;i<=(n/3)*2;i++){
            for(int j=1;j<=m;j++)if(a[i][j]!=2)ok&=1;
    }
    for(int i=(n/3)*2+1;i<=n;i++){
            for(int j=1;j<=m;j++)if(a[i][j]!=3)ok&=1;
    }
    for(int j=1;j<=m/3;j++){
            for(int i=1;i<=n;i++)if(a[i][j]!=1)ok&=2;
    }
    for(int j=(m/3)+1;j<=(m/3)*2;j++){
            for(int i=1;i<=n;i++)if(a[i][j]!=2)ok&=2;
    }
    for(int j=(m/3)*2+1;j<=m;j++){
            for(int i=1;i<=n;i++)if(a[i][j]!=3)ok&=2;
    }
    if(ok)puts("YES");
    else puts("NO");
//	system("pause");
	return 0;
}