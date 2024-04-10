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
#define orz  998244353ll
using namespace std;
int n,a[300005];
ll s[300005],ny;
ll fp(ll x,int k){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%orz;
        k>>=1;
        x=x*x%orz;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    ny=fp(n,998244351);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[n+1-i];
    for(int i=1;i<=n;++i){
        ll ans=0;
        for(int j=0;j<=n;++j){
            int l=i*j+1,r=l+i-1;
            if(r<n)(ans+=(s[r]-s[l-1])*j)%=orz;
            else (ans+=(s[n]-s[l-1])*j)%=orz,j=n;
        }
        ans=ans*ny%orz;
        ans=(ans+orz)%orz;
        if(i<n)printf("%I64d ",ans);
        else printf("%I64d\n",ans);
    }
    //system("pause");
    return 0;
}