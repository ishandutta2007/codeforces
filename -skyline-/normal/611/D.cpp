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
int n,a[5005],b[5005][5005],f[5005][5005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%1d",a+i);
    for(int i=n;i;i--){
            for(int j=n;j>i;j--){
                    if(a[i]!=a[j])b[i][j]=i;
                    else if(j==n)b[i][j]=6000;
                    else b[i][j]=b[i+1][j+1];
            }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)f[i][j]=1;
    }
    for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                    if(!a[i]){
                              f[i][j]=f[i-1][j];
                              continue;
                    }
                    int x=(i<<1)-j-1,y=i-1;
                    int ans=f[y][y]-f[max(x,0)][y];
                    if(ans<0)ans+=1000000007;
                    if(x>0){
                            if(b[x][i]<i&&a[b[x][i]]<a[b[x][i]+i-x])ans+=f[x][y]-f[x-1][y];
                            if(ans<0)ans+=1000000007;
                            else if(ans>=1000000007)ans-=1000000007;
                    }
                    f[i][j]=f[i-1][j]+ans;
                    if(f[i][j]>=1000000007)f[i][j]-=1000000007;
            }
    }
    printf("%d\n",f[n][n]);                
   // system("pause");
    return 0;
}