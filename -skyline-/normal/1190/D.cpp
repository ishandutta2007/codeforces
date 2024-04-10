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
#define X    first
#define Y    second
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,x[200005],y[200005],a[200005],t[200005],k;
ll ans;
pair<int,int> p[200005];
void upd(int x){
    while(x<=k)++t[x],x+=(x&-x);
}
int get(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=(x&-x);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
    for(int i=1;i<=n;++i)p[i]=mp(x[i],i);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i){
        if(i==1||p[i].X!=p[i-1].X)++k;
        x[p[i].Y]=k;
    }
    for(int i=1;i<=n;++i)p[i]=mp(-y[i],x[i]);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i){
        if(!a[p[i].Y]){
            a[p[i].Y]=1;
            upd(p[i].Y);
        }
        int l=get(p[i].Y),r;
        if(i==n||p[i+1].X!=p[i].X)r=get(k);
        else r=get(p[i+1].Y-1);
        ans+=l*1ll*(r-l+1ll);
    }
    printf("%I64d\n",ans);
    //system("pause");
    return 0;
}