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
ll jc[1000005],njc[1000005],ans;
int n;
ll fpower(ll x,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%orz;
        k>>=1,x=x*x%orz;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    jc[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%orz;
    njc[n]=fpower(jc[n],orz-2ll);
    for(int i=n;i;--i)njc[i-1]=njc[i]*i%orz;
    ans=jc[n];
    for(int i=1;i<n;++i){
        ans=ans+jc[n]*njc[i]%orz*(jc[i]+orz-1ll)%orz;
        ans%=orz;
    }
    ans=(ans%orz+orz)%orz;
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}