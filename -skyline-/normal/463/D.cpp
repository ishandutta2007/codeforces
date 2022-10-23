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
bool f[1002][1002];
int a[1002],dp[1002],ans=1;
int main()
{
    int n,k,i,j,l;
    cin>>n>>k;
    for(i=1;i<=k;i++){
                      for(j=1;j<=n;j++)cin>>a[j];
                      for(j=1;j<n;j++){
                                       for(l=j+1;l<=n;l++)f[a[j]][a[l]]=1;
                      }
    }
    for(i=1;i<=n;i++){
                      for(j=1;j<i;j++)if(!f[a[i]][a[j]])dp[i]=max(dp[j],dp[i]);
                      dp[i]++;
                      ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
   // system("pause");
    return 0;
}