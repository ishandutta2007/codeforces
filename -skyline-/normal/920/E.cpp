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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int f[200005],ans,n,m,s,res[200005];
vector<int> v[200005];
int get(int x){return x==f[x]?x:f[x]=get(f[x]);}
void dfs(int x){
    s++;
    f[x]=get(x+1);
    int k=0;
    for(int i=get(1);i<=n;i=get(i+1)){
        while(k<v[x].size()&&v[x][k]<i)k++;
        if(k<v[x].size()&&v[x][k]==i){
            k++;
            continue;
        }
        dfs(i);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+1;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++){
        if(f[i]!=i) continue;
        s=0;
        dfs(i),ans++;
        res[ans]=s;
    }
    sort(res+1,res+ans+1);
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)printf("%d ",res[i]);
//	system("pause");
	return 0;
}