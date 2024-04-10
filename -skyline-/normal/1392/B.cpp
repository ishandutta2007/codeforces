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
int T,n,x,y,a[200005];
ll k;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%I64d",&n,&k);
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        x=y=a[1];
        for(int i=1;i<=n;++i){
            if(a[i]<x)x=a[i];
            if(a[i]>y)y=a[i];
        }
        if(k&1ll){
            for(int i=1;i<=n;++i)a[i]=y-a[i];
        }
        else{
            for(int i=1;i<=n;++i)a[i]-=x;
        }
        for(int i=1;i<n;++i)printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    //system("pause");
    return 0;
}