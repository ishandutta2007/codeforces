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
//:
#define M  1000000009
using namespace std;
long long c[4002][4002],b,w,n,ans;
int main()
{
    for(int i=1;i<=4000;i++){
            c[i][1]=c[i][i]=1;
            for(int j=2;j<i;j++){
                    c[i][j]=c[i-1][j-1]+c[i-1][j];
                    if(c[i][j]>=M)c[i][j]-=M;
            }
    }
    scanf("%I64d%I64d%I64d",&n,&w,&b);
    for(int i=1;i<n;i++){
            for(int j=1;j<n-i;j++){
                    ans+=c[w][n-j]*c[b][j];
                    ans%=M;
            }
    }
    for(long long i=2;i<=w;i++)ans*=i,ans%=M;
    for(long long i=2;i<=b;i++)ans*=i,ans%=M;
    printf("%I64d\n",ans);      
	//system("pause");
	return 0;
}