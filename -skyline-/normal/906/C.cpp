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
int n,m,x[250],y[250],f[25],dp[4195000],c[4195000],pr[4195000];
int P;
void out(int x){
    if(x==P) return;
    out(pr[x]);
    printf("%d ",c[x]+1);
}
int main(){
    scanf("%d%d",&n,&m);
    if(m==n*(n-1)/2){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",x+i,y+i);
        x[i]--,y[i]--;
        f[x[i]]|=(1<<y[i]);
        f[y[i]]|=(1<<x[i]);
    }
    for(int i=0;i<n;i++)f[i]|=(1<<i);
    register int o,O=(1<<n),p=1;
    for(register int i=1;i<n;++i)if((f[i]&p)==p)p|=(1<<i);
    for(o=0;o<O;++o)dp[o]=orz;
    dp[p]=0;
    P=p;
    for(o=0;o<O;++o){
        if(o<p&&(o&p)==o) continue;
        for(register int i=0;i<n;++i){
            if((1<<i)&o){
                register int j=f[i]|o;
                if(dp[j]>dp[o]+1)dp[j]=dp[o]+1,pr[j]=o,c[j]=i;
            }
        }
    }
    printf("%d\n",dp[O-1]);
    out(O-1);
//	system("pause");
	return 0;
}