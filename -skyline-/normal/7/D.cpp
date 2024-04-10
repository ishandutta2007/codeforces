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
int n,a[10000005],z[10000005],f[5000005],k,ans;
int main(){
    char c=getchar();
    while(c!='\n'){
        a[++n]=c;
        c=getchar();
    }
    for(int i=1;i<=n;++i)a[n*2+1-i]=a[i];
    a[n*2+1]='?';
    z[1]=n*2;
    for(int i=2;i<=n*2;++i){
        if(i>=k+z[k]-1){
            while(a[1+z[i]]==a[i+z[i]])++z[i];
            k=i;
            continue;
        }
        if(z[i+1-k]<k+z[k]-i){
            z[i]=z[i+1-k];
            continue;
        }
        z[i]=z[k]+k-i;
        while(a[1+z[i]]==a[i+z[i]])++z[i];
        k=i;
    }
    for(int i=1;i<=n;++i){
        if(z[n*2+1-i]<i) continue;
        f[i]=f[i/2]+1;
        ans+=f[i];
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}