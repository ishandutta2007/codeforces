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
using namespace std;
int n,m,a[405],s[250005],t[250005],c[250005],r[250005],p[250005];
ll ans;
bool ok(int x,ll y){
    y/=c[x];
    int cnt=0;
    ll o=y;
    for(int i=s[x]+1;i<=t[x];++i){
        if(a[i]>y) return 0;
        if(o<a[i])o=y,++cnt;
        o-=a[i];
    }
    return cnt<=r[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=n;i;--i)a[i]-=a[i-1];
    for(int i=1;i<=m;++i)scanf("%d%d%d%d",s+i,t+i,c+i,r+i),p[i]=i;
    random_shuffle(p+1,p+m+1);
    for(int i=1;i<=m;++i){
        if(ok(p[i],ans)) continue;
        for(int j=59;j>=0;--j)if(!ok(p[i],ans+(1ll<<j)))ans+=(1ll<<j);
        ++ans;
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}