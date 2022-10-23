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
//
//
int n;
int q[4005],l[2005],r[2005],Q,ans[2005];
set<int> s;
map<int,int> m;
pair<int,int> p[2005];
vector<int> v[4005];
vector<int> res[2005];
bool b[2005];
void cty(int x){
     b[x]=1;
     int f[4005],g[4005];
     memset(f,0,sizeof(f));
     memset(g,0,sizeof(g));
     f[l[x]]=0;
     for(int i=l[x]+1;i<=r[x];i++){
             f[i]=f[i-1];
             g[i]=g[i-1];
             for(int j=0;j<v[i].size();j++){
                     if(l[v[i][j]]<l[x]||v[i][j]==x) continue;
                     if(!b[v[i][j]])cty(v[i][j]);
                     if(f[l[v[i][j]]]+ans[v[i][j]]>f[i]){
                                                         f[i]=f[l[v[i][j]]]+ans[v[i][j]];
                                                         g[i]=v[i][j];
                     }
             }
     }
     ans[x]=f[r[x]]+1;
     res[x].pb(x);
     int k=r[x];
     while(f[k]&&k>=l[x]){
                 for(int j=0;j<res[g[k]].size();j++)res[x].pb(res[g[k]][j]);
                 k=l[g[k]];
     }
}                
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            l[i]=a-b;
            r[i]=a+b;
            if(!s.count(l[i]))q[++Q]=l[i],s.insert(l[i]);
            if(!s.count(r[i]))q[++Q]=r[i],s.insert(r[i]);
    }
    sort(q+1,q+Q+1);
    for(int i=1;i<=Q;i++)m[q[i]]=i;
    for(int i=1;i<=n;i++)l[i]=m[l[i]],r[i]=m[r[i]]; 
    n++;
    l[n]=0,r[n]=Q+1;
    Q++;
    for(int i=1;i<=n;i++)v[r[i]].pb(i); 
    for(int i=1;i<=n;i++)if(!b[i])cty(i);  
    printf("%d\n",ans[n]-1);
    for(int i=1;i<res[n].size();i++)printf("%d ",res[n][i]);
	//system("pause");
	return 0;
}