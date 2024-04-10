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
ll k,a,b,c,f[2005][2005],ans;
ll fpower(ll x,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%orz;
        x=x*x%orz;
        k>>=1;
    }
    return ans;
}

int main(){
    cin>>k>>a>>b;
    c=a+b;
    f[0][1]=1;
    a=a*fpower(c,orz-2)%orz;
    b=b*fpower(c,orz-2)%orz;
    c=a*fpower(b,orz-2)%orz;
    for(int i=0;i<=k;++i){
        for(int j=0;j<=k;++j){
            if(i+j>=k)ans+=f[i][j]*(i+j+c)%orz;
            else f[i+j][j]=(f[i+j][j]+f[i][j]*b)%orz,f[i][j+1]=(f[i][j+1]+f[i][j]*a)%orz;
        }
    }
    cout<<(ans%orz)<<endl;
//	system("pause");
	return 0;
}