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
using namespace std;
int n,s[500005],a[500005],q[500005];
ll f[500005],ans;
vector<int> v[500005];
ll c(ll x){return x*(x-1ll)/2ll;}
void upd(ll &x,ll y){if(!x||x>y)x=y;}
bool cmp(int x,int y){return s[x]>s[y];}
double xl(int x,int y){
    return (f[x]*1.0-f[y])/(s[x]-s[y])+(s[x]+s[y]-1.0)/2;
}
void ope(int x,int y){
    s[x]=1;
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==y) continue;
        ope(v[x][i],x);
        s[x]+=s[v[x][i]];
    }
}
void dfs(int x,int y){
    vector<int> V;
    for(int i=0;i<v[x].size();++i){
        int z=v[x][i];
        if(y==z) continue;
        dfs(z,x);
        V.pb(z);
        upd(ans,f[z]+c(n-s[z]));
        upd(f[x],f[z]+c(s[x]-s[z]));
    }
    int k=V.size();
    for(int i=1;i<=k;++i)a[i]=V[i-1];
    sort(a+1,a+k+1,cmp);
    int l=1,r=0;
    for(int i=1;i<=k;++i){
        while(l<r&&xl(q[l],q[l+1])>=n-s[a[i]]-0.5)++l;
        if(l<=r)upd(ans,f[a[i]]+f[q[l]]+c(n-s[a[i]]-s[q[l]]));
        while(l<r&&xl(q[r-1],q[r])<=xl(q[r],a[i]))--r;
        q[++r]=a[i];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    ope(1,0);
    dfs(1,0);
    printf("%I64d\n",c(n)*2ll-ans);
    //system("pause");
    return 0;
}