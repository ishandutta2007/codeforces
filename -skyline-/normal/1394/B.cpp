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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int ans,n,m,k,cnt[200005],a[200005][12],f[50][50],num[12][12],N,mas[200005][50],b[50],C[12][12],X[50],Y[50];
pair<int,int> p[200005][12];
vector<int> vx[50],vy[50];
void dfs(int x){
    if(x==k){
        for(int i=1;i<=k;++i)if(!C[k][i]&&!f[num[k][i]][0])++ans;
        return;
    }
    for(int i=1;i<=x;++i){
        if(C[x][i]) continue;
        int o=num[x][i];
        if(f[o][0]) continue;
        for(int j=0;j<vx[o].size();++j)++C[vx[o][j]][vy[o][j]];
        dfs(x+1);
        for(int j=0;j<vx[o].size();++j)--C[vx[o][j]][vy[o][j]];
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;++i){
        for(int j=1;j<=i;++j){
            num[i][j]=++N;
            X[N]=i;
            Y[N]=j;
        }
    }
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        p[x][++cnt[x]]=mp(z,y);
    }
    for(int i=1;i<=n;++i){
        sort(p[i]+1,p[i]+cnt[i]+1);
        for(int j=1;j<=cnt[i];++j)++mas[p[i][j].second][num[cnt[i]][j]];
    }
    for(int i=1;i<=n;++i){
        int B=0;
        for(int j=1;j<=N;++j){
            if(mas[i][j]>1)f[j][0]=1;
            if(mas[i][j]==1)b[++B]=j;
        }
        for(int j=1;j<B;++j){
            for(int x=j+1;x<=B;++x)f[b[j]][b[x]]=1;
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j)if(f[i][j]||f[j][i])f[i][j]=f[j][i]=1;
    }
    for(int i=1;i<=N;++i){
        for(int j=i+1;j<=N;++j)if(f[i][j])vx[i].pb(X[j]),vy[i].pb(Y[j]);
    }
    dfs(1);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}