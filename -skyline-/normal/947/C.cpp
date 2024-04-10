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
int n,a[300005],p[300005],t[10000005],l[10000005],r[10000005],k=1;
void ins(int x){
    int o=1;
    for(int i=30;i>=0;--i){
        if((1<<i)&x){
            if(!l[o])l[o]=++k;
            o=l[o];
        }
        else{
            if(!r[o])r[o]=++k;
            o=r[o];
        }
        ++t[o];
    }
}
int get(int x){
    int o=1,ans=0;
    for(int i=30;i>=0;--i){
        if((1<<i)&x){
            if(t[l[o]])o=l[o];
            else o=r[o],ans+=(1<<i);
        }
        else{
            if(t[r[o]])o=r[o];
            else o=l[o],ans+=(1<<i);
        }
        --t[o];
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<=n;++i)scanf("%d",p+i),ins(p[i]);
    for(int i=1;i<=n;++i)printf("%d ",get(a[i]));
//	system("pause");
	return 0;
}