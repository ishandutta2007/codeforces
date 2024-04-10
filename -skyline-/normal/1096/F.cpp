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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,k,a[200005],s[200005];
ll jc[200005],njc[200005],ny[200005];
ll ans;
ll fp(ll x,int k=998244351){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%orz;
        k>>=1,x=x*x%orz;
    }
    return ans;
}
struct BIT{
    int a[200005];
    void clr(){
        memset(a,0,sizeof(a));
    }
    void add(int x,int k){
        while(x<=n)a[x]+=k,x+=(x&-x);
    }
    int get(int x){
        int ans=0;
        while(x)ans+=a[x],x-=(x&-x);
        return ans;
    }
}t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i),s[i]=1;
    jc[0]=1;
    for(int i=1;i<=200000;++i)jc[i]=jc[i-1]*i%orz;
    njc[200000]=fp(jc[200000]);
    for(int i=200000;i;--i)njc[i-1]=njc[i]*i%orz;
    for(int i=1;i<=200000;++i)ny[i]=njc[i]*jc[i-1]%orz;
    for(int i=1;i<=n;++i){
        if(a[i]==-1)++k;
        else{
            ans+=t.get(n+1-a[i]);
            ans%=orz;
            t.add(n+1-a[i],1);
            s[a[i]]=0;
        }
    }
    ans+=k*(k-1ll)%orz*ny[4]%orz;
    ans%=orz;
    t.clr();
    int cnt=0;
    for(int i=1;i<=n;++i)s[i]+=s[i-1];
    for(int i=1;i<=n;++i){
        if(a[i]==-1)++cnt;
        else{
            ans+=cnt*1ll*(k-s[a[i]])%orz*ny[k]%orz;
            ans%=orz;
            ans+=(k-cnt)*1ll*s[a[i]]%orz*ny[k]%orz;
            ans%=orz;
        }
    }
    printf("%I64d\n",(ans%orz+orz)%orz);
	//system("pause");
	return 0;
}