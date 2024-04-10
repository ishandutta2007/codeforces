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
int n,r,cnt[1005],f[1005],d[1005];
vector<int> v[1005],e[1005];
vector<int> res,rx,ry;
void add(int x,int y,int z){
    if(!z) return;
    res.pb(z),rx.pb(x),ry.pb(y);
}
void pre(int x,int y){
    d[x]=x,f[x]=y;
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]!=y){
            pre(v[x][i],x);
            d[x]=d[v[x][i]];
        }
    }
}
void sol(int x,int y,int z){
    if(cnt[x]==1&&cnt[y]==1){
        add(x,y,z);
        return;
    }
    if(cnt[x]==1)swap(x,y);
    int xa=0,xb=0;
    for(int i=0;i<v[x].size();++i){
        int o=v[x][i];
        if(o==y) continue;
        if(!xa)xa=o;
        else if(!xb)xb=o;
        else break;
    }
    xa=(xa==f[x])?r:d[xa];
    xb=(xb==f[x])?r:d[xb];
    if(cnt[y]==1){
        add(xa,y,z/2);
        add(xb,y,z/2);
        add(xa,xb,-z/2);
        return;
    }
    int ya=0,yb=0;
    for(int i=0;i<v[y].size();++i){
        int o=v[y][i];
        if(o==x) continue;
        if(!ya)ya=o;
        else if(!yb)yb=o;
        else break;
    }
    ya=(ya==f[y])?r:d[ya];
    yb=(yb==f[y])?r:d[yb];
    add(xa,ya,z/2);
    add(xb,yb,z/2);
    add(xa,xb,-z/2);
    add(ya,yb,-z/2);
}
void dfs(int x,int y){
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]!=y){
            sol(x,v[x][i],e[x][i]);
            dfs(v[x][i],x);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v[x].pb(y),v[y].pb(x);
        e[x].pb(z),e[y].pb(z);
        ++cnt[x],++cnt[y];
    }
    bool ok=1;
    for(int i=1;i<=n;++i)if(cnt[i]==2)ok=0;
    if(!ok){
        puts("NO");
        return 0;
    }
    printf("YES\n");
    for(int i=1;i<=n;++i)if(cnt[i]==1)r=i;
    pre(r,0);
    dfs(r,0);
    printf("%d\n",res.size());
    for(int i=0;i<res.size();++i)printf("%d %d %d\n",rx[i],ry[i],res[i]);
    //system("pause");
    return 0;
}