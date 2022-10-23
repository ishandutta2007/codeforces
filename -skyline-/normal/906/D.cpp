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
int get(){
    register char c=getchar();
    register int o=0;
    while(c<48)c=getchar();
    while(c>47)o=o*10+c-48,c=getchar();
    return o;
}
int O[20],B;
void out(register ll x){
     if(!x){
            puts("0");
            return;
     }
     while(x)O[++B]=x%10,x/=10;
     while(B)putchar(O[B--]+48);
     putchar('\n');
}
int n,m,w[100005],l[100005],r[100005],f[105],s;
ll ok;
ll fpower(register ll x,register ll k,register ll p){
    register ll ans=1;
    ok=0;
    while(k){
        if(k&1){
            ans*=x;
            if(ans>=p)ans%=p,ok=p;
        }
        k>>=1;
        x*=x;
        if(x>=p)x%=p,ok=p;
    }
    return ans+ok;
}
ll sol(register int L,register int R,register int K){
    if(L==R){
        if(w[L]<f[K]){
            ok=0;
            return w[L]%f[K];
        }
        else{
            ok=f[K];
            return w[L]%f[K]+f[K];
        }
    }
    return fpower(w[L],sol(L+1,R,K+1),f[K]);
}
int main(){
    n=get(),m=get();
    for(register int i=1;i<=n;++i)w[i]=get();
    f[0]=m;
    while(f[s]>1){
        register int t=f[s],T=t;
        for(register int i=2;i*i<=T;++i){
            if(T%i==0){
                t=t/i*(i-1);
                while(T%i==0)T/=i;
            }
        }
        if(T>1)t=t/T*(T-1);
        f[++s]=t;
    }
    f[++s]=1,f[++s]=1;
    register int q=get();
    for(register int i=1;i<=q;++i)l[i]=get(),r[i]=min(l[i]+s,get());
    for(register int i=1;i<=q;++i)ok=0,out(sol(l[i],r[i],0)-ok);
//	system("pause");
	return 0;
}