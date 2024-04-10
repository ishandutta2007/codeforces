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
int n,m,x[200005],y[200005],z[200005],ans[200005],s[200005];
vector<int> v[200005],e[200005];
queue<int> q;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)scanf("%d%d%d",x+i,y+i,z+i),v[x[i]].pb(y[i]),v[y[i]].pb(x[i]),e[x[i]].pb(i),e[y[i]].pb(i),s[x[i]]+=z[i],s[y[i]]+=z[i];
    memset(ans,-1,sizeof(ans));
    q.push(1);
    while(!q.empty()){
        int o=q.front();
        q.pop();
        for(int i=0;i<v[o].size();++i){
            if(ans[e[o][i]]!=-1) continue;
            int E=e[o][i];
            ans[E]=(x[E]!=o);
            s[v[o][i]]-=(z[E]<<1);
            if(!s[v[o][i]]&&v[o][i]!=n)q.push(v[o][i]);
        }
    }
    for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
//	system("pause");
	return 0;
}