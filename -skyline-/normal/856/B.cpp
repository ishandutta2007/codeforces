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
using namespace std;
int T,n,ch[1000006][26],k,len[1000005],f[1000005],q[1000005],dp[1000005][2];
vector<int> v[1000005];
void dfs(int x,int y){
    dp[x][1]=1;
    for(int i=0;i<v[x].size();++i){
        int z=v[x][i];
        if(z==y) continue;
        dfs(z,x);
        dp[x][0]+=max(dp[z][0],dp[z][1]);
        dp[x][1]+=dp[z][0];
    }
}
void solve(){
    while(k>=0){
        memset(ch[k],0,sizeof(ch[k]));
        len[k]=f[k]=0;
        --k;
    }
    k=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int o=0;
        char c=getchar();
        while(c<97)c=getchar();
        while(c>96){
            int p=c-97;
            if(!ch[o][p])len[ch[o][p]=++k]=len[o]+1;
            o=ch[o][p],c=getchar();
        }
    }
    int qr=0;
    for(int i=0;i<26;++i)if(ch[0][i])q[++qr]=ch[0][i];
    for(int ql=1;ql<=qr;++ql){
        int o=q[ql];
        for(int i=0;i<26;++i){
            if(ch[o][i])f[ch[o][i]]=ch[f[o]][i],q[++qr]=ch[o][i];
            else ch[o][i]=ch[f[o]][i];
        }
    }
    for(int i=1;i<=k;++i)v[i].clear(),dp[i][0]=dp[i][1]=0;
    for(int i=1;i<=k;++i)if(f[i]&&len[f[i]]==len[i]-1)v[f[i]].pb(i);
    int ans=0;
    for(int i=1;i<=k;++i){
        if(f[i]&&len[f[i]]==len[i]-1) continue;
        dfs(i,0);
        ans+=max(dp[i][0],dp[i][1]);
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    //system("pause");
    return 0;
}