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
int n,m,f[105][105][105],g[105][105][105],dp[105][105],pw[105];
void u(int &x,int y){if(y>x)x=y;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        pw[i]=i*i;
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            int l,r;
            scanf("%d%d",&l,&r);
            for(int k=l;k<=r;++k)++f[k][l][r],++g[k][l][r];
        }
    }
    for(int k=1;k<=m;++k){
        for(int i=m;i;--i){
            for(int j=i;j<=m;++j){
                f[k][i-1][j]+=f[k][i][j];
                g[k][i-1][j]+=f[k][i][j];
                g[k][i][j+1]+=g[k][i][j];
            }
        }
    }
    for(int i=1;i<=m;++i)dp[i][i]=pw[g[i][i][i]];
    for(int d=1;d<m;++d){
        for(int i=1;i<=m-d;++i){
            int _=i+d;
            for(int j=i;j<=_;++j)u(dp[i][_],dp[i][j-1]+dp[j+1][_]+pw[g[j][i][_]]);
        }
    }
    printf("%d\n",dp[1][m]);
    //system("pause");
    return 0;
}