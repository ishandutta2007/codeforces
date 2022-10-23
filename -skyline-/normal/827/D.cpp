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
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
#define X       first
#define Y       second
using namespace std;
int n,m,x[200005],y[200005],z[200005],ans[200005],b[200005],d[200005],f[200005][18],g[200005][18],pa[200005],A[200005];
vector<int> v[200005],e[200005];
pair<int,int> P[200005];
int fnd(int x){return x==pa[x]?x:pa[x]=fnd(pa[x]);}
void ope(int x,int y){
	d[x]=d[y]+1,f[x][0]=y;
	for(int i=0;i<17;++i)f[x][i+1]=f[f[x][i]][i],g[x][i+1]=max(g[x][i],g[f[x][i]][i]);
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)g[v[x][i]][0]=z[A[v[x][i]]=e[x][i]],ope(v[x][i],x);
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=17;i>=0;--i)if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y) return x;
	for(int i=17;i>=0;--i)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)pa[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%d",x+i,y+i,z+i),P[i]=mp(z[i],i);
	sort(P+1,P+m+1);
	for(int i=1;i<=m;++i){
        int I=P[i].Y,p=x[I],q=y[I];
        if(fnd(p)!=fnd(q))pa[pa[p]]=pa[q],b[I]=1,v[p].pb(q),v[q].pb(p),e[p].pb(I),e[q].pb(I);
    }
	ope(1,0);
	for(int i=1;i<=n;++i)pa[i]=i;
	for(int i=1;i<=m;++i){
        int I=P[i].Y;
		if(b[I]){ans[I]=orz;continue;}
		int p=x[I],q=y[I],r=lca(p,q);
		for(int j=17;j>=0;--j)if(d[f[p][j]]>=d[r])ans[I]=max(ans[I],g[p][j]),p=f[p][j];
		for(int j=17;j>=0;--j)if(d[f[q][j]]>=d[r])ans[I]=max(ans[I],g[q][j]),q=f[q][j];
	    p=fnd(x[I]),q=fnd(y[I]);
	    while(p!=q){
            if(d[p]<d[q])swap(p,q);
            ans[A[p]]=z[I];
            p=pa[p]=fnd(f[p][0]);
        }
    }
	for(int i=1;i<=m;++i)ans[i]=(ans[i]==orz)?-1:ans[i]-1;
	for(int i=1;i<m;++i)printf("%d ",ans[i]);
	printf("%d\n",ans[m]);
//	system("pause");
	return 0;
}