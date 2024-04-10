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
//:
using namespace std;
ll jc[100005],fac[12],vp[12],P[12],s,v[100005][12],r[100005][12];
ll n,L,R,p;
ll fpower(ll x,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%p;
        x=x*x%p;
        k>>=1;
    }
    if(!ans) return p;
    return ans;
}
ll c(ll x,ll y){
    ll m[12]={},ans=0;
    for(ll i=1;i<=s;++i){
        ll o=v[x][i]-v[y][i]-v[x-y][i];
        if(o>=vp[i]) continue;
        ll q=fpower(fac[i],vp[i]-o);
        m[i]=fpower(fac[i],o)*(r[x][i]*fpower(r[y][i]*r[x-y][i]%q,q/fac[i]*(fac[i]-1)-1)%q)%P[i];
        ans+=m[i]*fpower(p/P[i],P[i]/fac[i]*(fac[i]-1))%p;
    }
    return ans%p;
}
int main(){
    scanf("%I64d%I64d%I64d%I64d",&n,&p,&L,&R);
    jc[0]=1;
    for(ll i=1;i<=n;++i)jc[i]=jc[i-1]*i%p;
    ll t=p;
    for(ll i=2;i*i<=t;++i){
        if(t%i) continue;
        fac[++s]=i;
        while(t%i==0)vp[s]++,t/=i;
        P[s]=fpower(fac[s],vp[s]);
    }
    if(t>1)fac[++s]=t,vp[s]=1,P[s]=t;
    for(ll i=1;i<=s;++i){
        r[0][i]=1;
        for(ll j=1;j<=n;++j){
            ll t=j,sum=0;
            while(t%fac[i]==0)t/=fac[i],sum++;
            v[j][i]=v[j-1][i]+sum,r[j][i]=r[j-1][i]*t%P[i];
        }
    }
    ll ans=0;
    for(ll i=0;i<=n;++i){
        ll o=0;
        if(i-L>=0)o+=c(i,(i-L)/2);
        if(i-R-1>=0)o-=c(i,(i-R-1)/2);
        ans=(ans+c(n,i)*o)%p;
    }
    printf("%I64d\n",(p+ans%p)%p);
	return 0;
}