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
using namespace std;
int n,m,b,M,a[600],f[3][505][505],ans;
int main()
{
    scanf("%d%d%d%d",&n,&m,&b,&M);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
            int l=i&1;
            for(int j=0;j<=m;j++){
                    for(int k=0;k<=b;k++){
                            f[l][j][k]=f[l^1][j][k];
                            if(j>0&&k>=a[i])f[l][j][k]+=f[l][j-1][k-a[i]];
                            while(f[l][j][k]>=M)f[l][j][k]-=M;
                    }
            }
    }
    int l=n&1;
    for(int i=0;i<=b;i++){
            ans+=f[l][m][i];
            while(ans>=M)ans-=M;
    }
    printf("%d\n",ans);    
   // system("pause");
    return 0;
}