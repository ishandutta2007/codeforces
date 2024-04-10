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
//:
using namespace std;
ll dp[40][1005];
int main()
{
    int q;
    scanf("%d",&q);
    dp[0][0]=1;
    for(int i=1;i<=36;i++){
            dp[i][0]=dp[i][1]=1;
            for(int k=0;k<4;k++){
                    for(int j=1001;j>0;j--){
                            if(!dp[i][j]) continue;
                            for(int l=1;l<1001-j;l++){
                                    if(!dp[i-1][l]) break;
                                    dp[i][j+l]=(dp[i][j+l]+dp[i][j]*dp[i-1][l])%7340033;
                            }
                    }
            }
    }      
    while(q--){
               int n,k,s=0;
               scanf("%d%d",&n,&k);
               while(n>1&&(n&1))n>>=1,s++;
               printf("%I64d\n",dp[s][k]);
    }
	//system("pause");
	return 0;
}