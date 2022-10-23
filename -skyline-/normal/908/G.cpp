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
int n,a[705];
ll ans,t[705],dp[705][705][2];
int main(){
    char c=getchar();
    while(c>47)a[++n]=c-48,c=getchar();
    t[1]=1;
    for(int i=2;i<=n;++i)t[i]=t[i-1]*10ll%orz;
    for(int i=2;i<=n;++i)(t[i]+=t[i-1])%=orz;
    for(int _=1;_<=9;++_){
        memset(dp,0,sizeof(dp));
        dp[0][0][1]=1;
        for(int i=1;i<=n;++i){
            int __=min(_,a[i]);
            for(int j=0;j<i;++j){
                dp[i][j+1][0]+=dp[i-1][j][0]*(10-_);
                dp[i][j][0]+=dp[i-1][j][0]*_;
                dp[i][j][0]+=dp[i-1][j][1]*__;
                dp[i][j+1][0]+=dp[i-1][j][1]*(a[i]-__);
                dp[i][j+(_==__)][1]+=dp[i-1][j][1];
            }
            for(int j=0;j<=i;++j)dp[i][j][0]%=orz,dp[i][j][1]%=orz;
        }
        for(int i=1;i<=n;++i)(ans+=(dp[n][i][0]+dp[n][i][1])*t[i])%=orz;
    }
    printf("%I64d\n",(ans%orz+orz)%orz);
  //  system("pause");
    return 0;
}