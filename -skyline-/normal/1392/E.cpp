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
int n,q;
ll k,a[30][30];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=n;++j){
            if(i==j&&(i==1||i==n)) continue;
            a[i][j]=1ll<<(i+j-3ll);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<n;++j)printf("%I64d ",a[i][j]);
        printf("%I64d\n",a[i][n]);
    }
    fflush(stdout);
    scanf("%d",&q);
    while(q--){
        scanf("%I64d",&k);
        int x=1,y=1;
        printf("1 1\n");
        for(ll i=0;i<=2*n-4;++i){
            if(k&(1ll<<i)){
                if(x&1)++y;
                else ++x;
            }
            else{
                if(x&1)++x;
                else ++y;
            }
            printf("%d %d\n",x,y);
        }
        printf("%d %d\n",n,n);
        fflush(stdout);
    }
    //system("pause");
    return 0;
}