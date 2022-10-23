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
using namespace std;
int n,d,m,f[30003],ans,ma;
int dp[30003][503];
inline int ope(int x,int Y){
       int y=Y-d-250;
       if(dp[x][y]!=-1) return dp[x][y];
       dp[x][y]=0;
       if(Y==1){
                for(int i=x;i<=m;i++)dp[x][y]+=f[i];
                return dp[x][y];
       }       
       if(x+Y+1<=m) dp[x][y]=ope(x+Y+1,Y+1);
       if(x+Y<=m) dp[x][y]=max(dp[x][y],ope(x+Y,Y));
       if(x+Y-1<=m) dp[x][y]=max(dp[x][y],ope(x+Y-1,Y-1));
       dp[x][y]+=f[x];
       return dp[x][y];
}


int main()
{
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            f[k]++;
            m=max(m,k);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",ope(d,d));
   // system("pause");
    return 0;
}