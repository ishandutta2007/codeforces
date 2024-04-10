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
//:
using namespace std;
int n,k;
ll s[2][5002],c[2][5002];
ll ans;
ll fpower(ll x,int k){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%orz;
        x=x*x%orz;
        k>>=1;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    if(n>=k){
        s[1][1]=1;
        for(int i=2;i<=k;++i){
            int x=i&1,y=x^1;
            for(ll j=1;j<=i;++j)s[x][j]=(s[y][j-1]+s[y][j]*j)%orz;
        }
        ll o=1;
        for(int i=1;i<=k;++i){
            o=o*(n-i+1ll)%orz;
            ans+=o*fpower(2,n-i)%orz*s[k&1][i]%orz;
            ans%=orz;
        }
    }
    else{
        c[0][0]=1;
        for(int i=1;i<=n;++i){
            int x=i&1,y=x^1;
            c[x][0]=c[x][i]=1;
            for(int j=1;j<i;++j)c[x][j]=(c[y][j-1]+c[y][j])%orz;
        }
        for(int i=1;i<=n;++i)ans+=fpower(i,k)*c[n&1][i]%orz,ans%=orz;
    }
    printf("%I64d\n",ans%orz);
	//system("pause");
	return 0;
}