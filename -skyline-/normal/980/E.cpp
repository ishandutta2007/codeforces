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
int n,k,f[1000005][22],b[1000005],u[1000005],d[1000005];
vector<int> v[1000005];
void dfs(int x,int y){
    d[x]=d[y]+1,f[x][0]=y;
    for(int i=0;i<19;++i)f[x][i+1]=f[f[x][i]][i];
    for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs(v[x][i],x);
}
int main(){
    scanf("%d%d",&n,&k),u[n]=u[0]=1,k=n-k-1;
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    dfs(n,0);
    for(int i=n-1;i>=1;--i){
        if(u[i]) continue;
        int x=i;
        for(int j=19;j>=0;--j)if(!u[f[x][j]])x=f[x][j];
        if(d[i]-d[x]+1<=k){
            k-=d[i]-d[x]+1;
            x=i;
            while(!u[x])u[x]=1,x=f[x][0];
        }
        else b[i]=1;
    }
    for(int i=1;i<n;++i)if(b[i])printf("%d ",i);
    printf("\n");
	return 0;
}