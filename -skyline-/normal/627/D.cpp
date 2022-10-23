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
int n,k,a[200005],s[200005],_,A,d[200005],u[200005],r[200005],P,Q;
vector<int> v[200005];
void ope(int x,int y){
    s[x]=1;
    for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)ope(v[x][i],x),s[x]+=s[v[x][i]];
}
void dfs1(int x,int y){
    if(a[x]<_){
        d[x]=0;
        for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs1(v[x][i],x);
        return;
    }
    d[x]=1;
    int o=0;
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==y) continue;
        dfs1(v[x][i],x);
        if(d[v[x][i]]==s[v[x][i]])d[x]+=d[v[x][i]];
        else o=max(o,d[v[x][i]]);
    }
    d[x]+=o;
}
void add(int x){
    if(x>P)Q=P,P=x;
    else if(x>Q)Q=x;
}
void dfs2(int x,int y){
    if(a[x]<_){
        r[x]=0;
        for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)u[v[x][i]]=0;
    }
    else{
        P=0,Q=0;
        int su=0;
        if(u[x]==n-s[x])su+=u[x];
        else add(u[x]);
        for(int i=0;i<v[x].size();++i){
            if(v[x][i]==y) continue;
            if(d[v[x][i]]==s[v[x][i]])su+=d[v[x][i]];
            else add(d[v[x][i]]);
        }
        r[x]=su+P+1;
        for(int i=0;i<v[x].size();++i){
            if(v[x][i]==y) continue;
            if(d[v[x][i]]==s[v[x][i]])u[v[x][i]]=su-d[v[x][i]]+P+1;
            else if(d[v[x][i]]==P)u[v[x][i]]=su+Q+1;
            else u[v[x][i]]=su+P+1;
        }
    }
    for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs2(v[x][i],x);
}
bool ok(){
    if(_>A) return 0;
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i)if(r[i]>=k) return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",a+i),A=max(A,a[i]);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    ope(1,0);
    int ans=0;
    for(int i=19;i>=0;--i){
        _=ans+(1<<i);
        if(ok())ans=_;
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}