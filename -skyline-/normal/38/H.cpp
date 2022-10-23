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
int n,m,g1,g2,s1,s2,f[55][55],G[55],S[55],B[55];
ll dp[52][52][52][2][2],ans;
pair<int,int> p[55][55];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)f[i][j]=orz;
        f[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        f[x][y]=f[y][x]=min(f[x][y],z);
    }
    scanf("%d%d%d%d",&g1,&g2,&s1,&s2);
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    for(int i=1;i<=n;++i)sort(f[i]+1,f[i]+n+1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)p[i][j]=mp(f[i][j],i);
    }
    for(int gg=1;gg<=n;++gg){
        pair<int,int> g=p[gg][2];
        for(int bb=1;bb<=n;++bb){
            pair<int,int> b=p[bb][n];
            if(b<=g) continue;
            for(int i=1;i<=n;++i){
                G[i]=(p[i][2]<=g),B[i]=(p[i][n]>=b),S[i]=0;
                for(int j=2;j<=n;++j)if(p[i][j]<b&&p[i][j]>g)S[i]=1,j=n;
            }
            memset(dp,0,sizeof(dp));
            dp[0][0][0][0][0]=1;
            for(int i=0;i<=g2;++i){
                for(int j=0;j<=s2;++j){
                    for(int k=0;k+i+j<n;++k){
                        int o=i+j+k+1;
                        if(G[o]){
                            if(p[o][2]==g){
                                dp[i+1][j][k][1][0]+=dp[i][j][k][0][0]+dp[i][j][k][1][0];
                                dp[i+1][j][k][1][1]+=dp[i][j][k][0][1]+dp[i][j][k][1][1];
                            }
                            else{
                                dp[i+1][j][k][0][0]+=dp[i][j][k][0][0];
                                dp[i+1][j][k][0][1]+=dp[i][j][k][0][1];
                                dp[i+1][j][k][1][0]+=dp[i][j][k][1][0];
                                dp[i+1][j][k][1][1]+=dp[i][j][k][1][1];
                            }
                        }
                        if(S[o]){
                            dp[i][j+1][k][0][0]+=dp[i][j][k][0][0];
                            dp[i][j+1][k][0][1]+=dp[i][j][k][0][1];
                            dp[i][j+1][k][1][0]+=dp[i][j][k][1][0];
                            dp[i][j+1][k][1][1]+=dp[i][j][k][1][1];
                        }
                        if(B[o]){
                            if(p[o][n]==b){
                                dp[i][j][k+1][0][1]+=dp[i][j][k][0][0]+dp[i][j][k][0][1];
                                dp[i][j][k+1][1][1]+=dp[i][j][k][1][0]+dp[i][j][k][1][1];
                            }
                            else{
                                dp[i][j][k+1][0][0]+=dp[i][j][k][0][0];
                                dp[i][j][k+1][0][1]+=dp[i][j][k][0][1];
                                dp[i][j][k+1][1][0]+=dp[i][j][k][1][0];
                                dp[i][j][k+1][1][1]+=dp[i][j][k][1][1];
                            }
                        }
                    }
                    if(i>=g1&&j>=s1&&n-i-j>=0)ans+=dp[i][j][n-i-j][1][1];
                }
            }
        }
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}