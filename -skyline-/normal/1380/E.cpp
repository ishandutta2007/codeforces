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
int n,m,f[600005],r[200005],a[200005],b[200005],fa[600005][20],d[600005],cnt[600005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",f+i),f[i]+=n;
    for(int i=1;i<=m;++i)r[i]=i+n;
    for(int i=1;i<m;++i){
        scanf("%d%d",a+i,b+i);
        f[r[a[i]]]=f[r[b[i]]]=n+m+i;
        r[a[i]]=n+m+i;
    }
    for(int i=1;i<=n+m*2-1;++i)fa[i][0]=f[i];
    for(int i=n+m*2-1;i;--i){
        d[i]=d[f[i]]+1;
        for(int j=0;j<19;++j)fa[i][j+1]=fa[fa[i][j]][j];
    }
    for(int i=1;i<n;++i){
        int x=i,y=i+1;
        if(d[x]<d[y])swap(x,y);
        for(int j=19;j>=0;--j)if(d[fa[x][j]]>=d[y])x=fa[x][j];
        for(int j=19;j>=0;--j)if(fa[x][j]!=fa[y][j])x=fa[x][j],y=fa[y][j];
        ++cnt[f[x]];
    }
    int ans=n-1;
    for(int i=n+1;i<=n+m;++i)ans-=cnt[i];
    printf("%d\n",ans);
    for(int i=1;i<m;++i){
        ans-=cnt[n+m+i];
        printf("%d\n",ans);
    }
   // system("pause");
    return 0;
}