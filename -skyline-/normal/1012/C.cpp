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
int n,a[5005],dp[5005][5005][3];
//0 00 1 10 2 01
void upd(int &x,int y){if(x==-1||x>y)x=y;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=0;i<n;++i){
        int k=(i&1)?i/2+1:i/2;
        for(int j=0;j<=k;++j){
            if(dp[i][j][0]>-1){
                upd(dp[i+1][j][0],dp[i][j][0]);
                upd(dp[i+1][j+1][2],dp[i][j][0]+max(0,a[i]-a[i+1]+1)+max(0,a[i+2]-a[i+1]+1));
            }
            if(dp[i][j][2]>-1){
                upd(dp[i+1][j][1],dp[i][j][2]);
            }
            if(dp[i][j][1]>-1){
                upd(dp[i+1][j][0],dp[i][j][1]);
                upd(dp[i+1][j+1][2],dp[i][j][1]+max(0,min(a[i],a[i-1]-1)-a[i+1]+1)+max(0,a[i+2]-a[i+1]+1));
            }
        }
    }
    for(int i=1;i<=(n+1)/2;++i){
        int ans=orz;
        if(dp[n][i][0]!=-1)upd(ans,dp[n][i][0]);
        if(dp[n][i][1]!=-1)upd(ans,dp[n][i][1]);
        if(dp[n][i][2]!=-1)upd(ans,dp[n][i][2]);
        if(i>1)printf(" ");
        printf("%d",ans);
    }
    printf("\n");
//	system("pause");
	return 0;
}