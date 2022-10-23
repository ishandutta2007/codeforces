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
int n,sz[100005];
double s[100005],t[100005],S,T,ans,f[100005];
vector<int> v[100005];
void dfs(int x,int y){
    double add=0;
    sz[x]=1,f[x]=s[x];
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==y) continue;
        dfs(v[x][i],x);
        sz[x]+=sz[v[x][i]],f[x]+=f[v[x][i]];
        add+=sz[v[x][i]]*f[v[x][i]];
    }
    add+=(n-sz[x])*(1.0-f[x]);
    ans+=add*t[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        s[i]=x*1.0,t[i]=y*1.0;
        S+=s[i],T+=t[i];
    }
    for(int i=1;i<=n;++i)s[i]/=S,t[i]/=T;
    dfs(1,0);
    printf("%.12lf\n",ans);
//	system("pause");
	return 0;
}