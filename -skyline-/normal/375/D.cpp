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
//:
using namespace std;
int n,m,s,c[100005],a[100005],L[100005],R[100005],l[100005],r[100005],k[100005],f[100005],cnt[100005],ans[100005];
vector<int> v[100005];
pair<pair<int,int>,int> p[100005];
void dfs(int x,int y){
    a[++s]=c[x],L[x]=s;
    for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs(v[x][i],x);
    R[x]=s;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",c+i);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    dfs(1,0);
    for(int i=1;i<=m;++i){
        int x;
        scanf("%d%d",&x,k+i);
        l[i]=L[x],r[i]=R[x];
        p[i].X.X=l[i]/300;
        if(p[i].X.X&1)p[i].X.Y=r[i];
        else p[i].X.Y=-r[i];
        p[i].Y=i;
    }
    sort(p+1,p+m+1);
    int x=1,y=0;
    for(int _=1;_<=m;++_){
        int i=p[_].Y;
        while(x>l[i])++cnt[++f[a[--x]]];
        while(y<r[i])++cnt[++f[a[++y]]];
        while(x<l[i])--cnt[f[a[x++]]--];
        while(y>r[i])--cnt[f[a[y--]]--];
        ans[i]=cnt[k[i]];
    }
    for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
//	system("pause");
	return 0;
}