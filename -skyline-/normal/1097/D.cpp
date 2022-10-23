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
#define orz  1000000007ll
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
ll n,N,a[105],f[55][10005][55],ny[100];
int k,b[105],m;
ll fpower(ll x,ll k=orz-2){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%orz;
        x=x*x%orz,k>>=1;
    }
    return ans;
}
int main(){
    for(int i=1;i<=80;++i)ny[i]=fpower(i);
    scanf("%I64d%d",&n,&k);
    N=n;
    for(ll i=2;i*i<=N;++i){
        if(N%i) continue;
        a[++m]=i;
        while(N%i==0)N/=i,++b[m];
    }
    if(N>1)a[++m]=N,b[m]=1;
    for(int i=1;i<=53;++i){
        f[i][0][i]=1;
        for(int j=1;j<=k;++j){
            for(int l=1;l<=i;++l){
                (f[i][j][l]+=f[i][j-1][l]*ny[l])%=orz;
            }
            for(int l=i-1;l>0;--l){
                f[i][j][l]+=f[i][j][l+1];
                if(f[i][j][l]>=orz)f[i][j][l]-=orz;
            }
        }
    }
    ll out=1;
    for(int i=1;i<=m;++i){
        a[i]%=orz;
        ++b[i];
        ll res=0,o=1;
        for(int j=1;j<=b[i];++j){
            (res+=o*f[b[i]][k][j])%=orz;
            o=o*a[i]%orz;
        }
        out=out*res%orz;
    }
    printf("%I64d\n",(out%orz+orz)%orz);
//	system("pause");
	return 0;
}