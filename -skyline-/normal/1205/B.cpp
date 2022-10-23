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
int n,k,d[150],ans,f[150][150];
map<int,int> m;
vector<int> v[65],e[150];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        ll x;
        scanf("%I64d",&x);
        for(int j=0;j<62;++j){
            if(x&(1ll<<j)){
                v[j].pb(i);
                if(v[j].size()>2){
                    puts("3");
                    return 0;
                }
            }
        }
    }
    for(int i=0;i<62;++i)if(v[i].size()==1)v[i].clear();
    for(int i=0;i<62;++i){
        if(v[i].size()<2) continue;
        int x=v[i][0],y=v[i][1];
        if(!m[x])m[x]=++k;
        if(!m[y])m[y]=++k;
        x=m[x],y=m[y];
        if(f[x][y]) continue;
        f[x][y]=1;
        e[x].pb(y),e[y].pb(x);
    }
    ans=orz;
    for(int i=1;i<=k;++i){
        memset(d,-1,sizeof(d));
        d[i]=0;
        queue<int> q,qb;
        q.push(i),qb.push(-1);
        while(!q.empty()){
            int x=q.front(),ba=qb.front();
            q.pop(),qb.pop();
            for(int j=0;j<e[x].size();++j){
                if(e[x][j]==ba) continue;
                if(d[e[x][j]]==-1){
                    d[e[x][j]]=d[x]+1;
                    q.push(e[x][j]);
                    qb.push(x);
                }
                else ans=min(ans,d[x]+d[e[x][j]]+1);
            }
        }
    }
    if(ans==orz)puts("-1");
    else printf("%d\n",ans);
    //system("pause");
    return 0;
}