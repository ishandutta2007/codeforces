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
int n,a[105],b[262222],c[105],f[410000][25],g[410000],k;
int main(){
    for(int i=1;i<262144;++i){
        if(i&1)b[i]=b[i>>1]+1;
        else b[i]=b[i>>1];
    }
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int _=0;_<4096;++_){
        for(int i=1;i<=n;++i)c[i]=b[(a[i]&4095)^_];
        int o=0;
        for(int i=2;i<=n;++i){
            int p=c[i]-c[i-1]+12;
            if(!f[o][p])f[o][p]=++k;
            o=f[o][p];
        }
        g[o]=_;
    }
    for(int _=0;_<262144;++_){
        for(int i=1;i<=n;++i)c[i]=b[(a[i]>>12)^_];
        int o=0;
        for(int i=2;i<=n;++i){
            int p=c[i-1]-c[i]+12;
            if(p<0||p>24||!f[o][p]){
                o=-1;
                break;
            }
            o=f[o][p];
        }
        if(o!=-1){
            int m=(_<<12)+g[o];
            printf("%d\n",(_<<12)+g[o]);
            return 0;
        }
    }
    puts("-1");
    //system("pause");
    return 0;
}