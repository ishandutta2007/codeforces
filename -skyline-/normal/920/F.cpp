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
int n,f[2000005],a[300005],m,o[300005];
bool b[2000005];
ll t[300005];
int get(int x){return x==o[x]?x:o[x]=get(o[x]);}
void add(int x,ll k){
    while(x<=n)t[x]+=k,x+=(x&-x);
}
ll sum(int x){
    ll ret=0;
    while(x)ret+=t[x],x-=(x&-x);
    return ret;
}
int main(){
    for(int i=1;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i)f[j]++;
    }    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i),o[i]=i,add(i,a[i]);
    o[n+1]=n+1;
    while(m--){
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1){
            for(int i=get(l);i<=r;i=get(i+1)){
                if(f[a[i]]==a[i])o[i]=i+1;
                else add(i,f[a[i]]-a[i]),a[i]=f[a[i]];
            }
        }
        else printf("%I64d\n",sum(r)-sum(l-1));
    }
	//system("pause");
	return 0;
}