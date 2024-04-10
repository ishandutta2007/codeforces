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
int n,a[705],f[705][705],x[705][705],y[705][705];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<n;++i){
        f[i][i]=1;
        for(int j=i+1;j<=n;++j){
            if(__gcd(a[i],a[j])>1)f[i][j]=f[j][i]=1;
        }
    }
    for(int i=1;i<=n;++i){
        if(f[i-1][i])x[i][i]=1;
        if(f[i][i+1])y[i][i]=1;
    }
    for(int l=2;l<=n;++l){
        for(int i=l;i<=n;++i){
            int I=i-l+1;
            if(x[I+1][i]){
                if(f[I][I-1])x[I][i]=1;
                if(f[I][i+1])y[I][i]=1;
            }
            if(y[I][i-1]){
                if(f[i][I-1])x[I][i]=1;
                if(f[i][i+1])y[I][i]=1;
            }
            for(int j=I+1;j<i;++j){
                if(y[I][j-1]&&x[j+1][i]){
                    if(f[j][I-1])x[I][i]=1;
                    if(f[j][i+1])y[I][i]=1;
                }
            }
        }
    }
    bool ok=0;
    if(x[2][n]||y[1][n-1])ok=1;
    for(int i=2;i<n;++i)if(x[1][i-1]&&y[i=1][n])ok=1;
    if(ok)puts("Yes");
    else puts("No");
//	system("pause");
	return 0;
}