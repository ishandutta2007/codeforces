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
int n,a[200005],b[200005],s[200005],k;
int cnt[100200001];
ll ans;
int main(){
    char c=getchar();
    while(c>47)a[++n]=c-48,c=getchar();
    for(int i=1;i<=n;++i)if(a[i])b[++k]=i;
    b[k+1]=n+1;
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int i=1;i<=500;++i){
        cnt[s[0]*i+n]=1;
        for(int j=1;j<=n;++j){
            ans+=(cnt[s[j]*i+n-j]++);
        }
        for(int j=0;j<=n;++j)--cnt[s[j]*i+n-j];
    }
    for(int i=1;i<=400;++i){
        for(int j=i;j<=k;++j){
            int L=b[j-i]+1,R=b[j+1]-1;
            int l=b[j-i+1],r=b[j];
            for(int _=L;_<=l;++_){
                int u=max((r-_)/i,500);
                ans+=max(0,(R-_+1)/i-u);
            }
        }
    }
    printf("%I64d\n",ans);
    //system("pause");
    return 0;
}