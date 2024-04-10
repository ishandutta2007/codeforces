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
int n,m,k,a[20],l[15];
vector<int> b[15],f[15][20];
int dp[32800][108],cnt[32800],ans=106,res;
string words[20];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        a[i]=-1;
        string s;
        cin>>s;
        for(int j=0;j<k;++j)if(words[j]==s)a[i]=j,j=k;
        if(a[i]==-1)a[i]=k,words[k++]=s;
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        b[i].pb(0);
        int w;
        cin>>w;
        string s;
        for(int j=1;j<=w;++j){
            cin>>s;
            for(int o=0;o<k;++o)if(words[o]==s)b[i].pb(o),o=k;
        }
        l[i]=b[i].size()-1;
        for(int j=0;j<k;++j){
            for(int o=-1;o<=l[i];++o)f[i][j].pb(0);
        }
        for(int j=l[i];j;--j){
            f[i][b[i][j]][j]=j;
            for(int o=0;o<k;++o)f[i][o][j-1]=f[i][o][j];
        }
    }
    for(int i=(1<<n)-1;i>=0;--i){
        for(int j=0;j<n;++j)if(i&(1<<j))++cnt[i];
    }
    for(int _=1;_<=m;++_){
        memset(dp,0,sizeof(dp));
        int ma=1<<n,M=n*(n-1)/2;
        for(int i=0;i<n;++i)dp[1<<i][0]=f[_][a[i]][0];
        for(int i=0;i<ma;++i){
            for(int j=0;j<=M;++j){
                if(!dp[i][j]) continue;
                for(int l=0;l<n;++l){
                    if((1<<l)&i) continue;
                    int N=j+cnt[i>>l],I=i|(1<<l),O=f[_][a[l]][dp[i][j]+1];
                    if(!O) continue;
                    if(!dp[I][N]||dp[I][N]>O)dp[I][N]=O;
                }
            }
        }
        for(int i=0;i<ans;++i)if(dp[ma-1][i])ans=i,res=_;
    }
    if(!res)puts("Brand new problem!");
    else{
        printf("%d\n",res);
        putchar('['),putchar(':');
        ans=n*(n-1)/2-ans+1;
        for(int i=1;i<=ans;++i)putchar('|');
        putchar(':'),putchar(']');
    } 
//	system("pause");
	return 0;
}