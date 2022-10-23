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
//:
using namespace std;
//
//
int n,f[5005],c[5005],d[5005],b,dp[5005][5005][5],s[5005];
int main()                               
{         
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++){
            s[i]=1;
            scanf("%d%d",c+i,d+i);
            d[i]=c[i]-d[i];
            if(i>1)scanf("%d",f+i);
    }
    for(int i=1;i<=n;i++){
            dp[i][0][0]=0,dp[i][0][1]=orz;
            dp[i][1][0]=c[i],dp[i][1][1]=d[i];
            for(int j=2;j<=n+1;j++)dp[i][j][0]=dp[i][j][1]=orz;
    }
    for(int i=n;i;i--){
            int p=f[i];
            for(int j=0;j<=s[i];j++)dp[i][j][1]=min(dp[i][j][1],dp[i][j][0]);
            for(int j=s[p];j>=0;j--){
                    for(int k=s[i];k>=0;k--){
                            dp[p][j+k][0]=min(dp[p][j+k][0],dp[i][k][0]+dp[p][j][0]);
                            dp[p][j+k][1]=min(dp[p][j+k][1],dp[i][k][1]+dp[p][j][1]);
                    }
            }
            s[p]+=s[i];
    }
    int ans=0;
    for(int i=0;i<=n;i++)if(min(dp[1][i][1],dp[1][i][0])<=b)ans=i;
	printf("%d\n",ans);
  //  system("pause");
	return 0;
}