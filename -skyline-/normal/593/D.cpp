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
//:
using namespace std;
//
//
int n,m,f[200005],get[200005];
vector<int> v[200005];
vector<ll> e[200005];
vector<int> id[200005];
int p[20][200005],d[200005];
ll q[200005];
int cty(int x){return x==f[x]?x:f[x]=cty(f[x]);}
void ope(int k,int l){
     d[k]=d[l]+1;
     p[0][k]=l;
     for(int i=1;i<=19;i++)p[i][k]=p[i-1][p[i-1][k]];
     for(int i=0;i<v[k].size();i++){
             if(v[k][i]!=l)ope(v[k][i],k);
             else{
                  q[k]=e[k][i],get[id[k][i]]=k;
                  if(q[k]==1)f[k]=f[p[0][k]];
             }
     }
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    for(int i=0;i<=19;i++)if((d[y]-d[x])>>i&1)y=p[i][y];
    for(int i=19;i>=0;i--){
            if(p[i][x]!=p[i][y])x=p[i][x],y=p[i][y];
    }
    if(x!=y)x=p[0][x];
    return x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
            int x,y;
            ll o;
            scanf("%d%d%I64d",&x,&y,&o);
            v[x].pb(y),e[x].pb(o),id[x].pb(i);
            v[y].pb(x),e[y].pb(o),id[y].pb(i);
    }                             
    for(int i=1;i<=n;i++)f[i]=i;
    ope(1,1);
    for(int i=1;i<=m;i++){
            int t;
            scanf("%d",&t);
            if(t==2){
                     int x;
                     ll c;
                     scanf("%d%I64d",&x,&c);
                     q[get[x]]=c;
                     if(c==1)f[get[x]]=cty(p[0][get[x]]);
                     continue;
            }  
            int x,y;
            ll ans;
            scanf("%d%d%I64d",&x,&y,&ans);
            int z=lca(x,y);
            x=cty(x),y=cty(y);
            while(d[x]>d[z]&&ans){
                                  ans/=q[x];
                                  x=cty(p[0][x]);
            }
            while(d[y]>d[z]&&ans){
                                  ans/=q[y];
                                  y=cty(p[0][y]);
            }
            printf("%I64d\n",ans);
    }            
//	system("pause");
	return 0;
}