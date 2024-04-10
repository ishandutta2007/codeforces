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
int n,c[100005],s[100005],son[100005];
vector<int> v[100005],V[100005];
int cnt[100005],num;
ll sum,ans[100005];
void ope(int x,int y){
    s[x]=1;
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==y) continue;
        int z=v[x][i];
        ope(z,x);
        s[x]+=s[z];
        if(s[z]>s[son[x]])son[x]=z;
    }
    for(int i=0;i<v[x].size();++i)if(v[x][i]!=y&&v[x][i]!=son[x])V[x].pb(v[x][i]);
}
void add(int x,int y){
    cnt[c[x]]+=y;
    if(y>0){
        if(cnt[c[x]]>num)num=cnt[c[x]],sum=c[x];
        else if(cnt[c[x]]==num)sum+=c[x];
    }
    for(int i=0;i<V[x].size();++i)add(V[x][i],y);
    if(son[x])add(son[x],y);
}
void dfs(int x,int y){
    for(int i=0;i<V[x].size();++i)dfs(V[x][i],0);
    if(son[x])dfs(son[x],1);
    for(int i=0;i<V[x].size();++i)add(V[x][i],1);
    ++cnt[c[x]];
    if(cnt[c[x]]>num)num=cnt[c[x]],sum=c[x];
    else if(cnt[c[x]]==num)sum+=c[x];
    ans[x]=sum;
    if(!y){
        add(x,-1);
        num=0,sum=0;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",c+i);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    ope(1,0);
    dfs(1,0);
    for(int i=1;i<n;++i)printf("%I64d ",ans[i]);
    printf("%I64d\n",ans[n]);
//	system("pause");
	return 0;
}