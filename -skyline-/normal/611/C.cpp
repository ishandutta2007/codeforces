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
char c[505][505];
int a[505][505],b[505][505],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf(" %c",c[i]+j);
    }
    for(int i=1;i<=502;i++)c[n+1][i]=c[i][m+1]='#';
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(c[i][j]=='.'&&c[i+1][j]=='.')a[i][j]=1;
                    if(c[i][j]=='.'&&c[i][j+1]=='.')b[i][j]=1;
                    a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
                    b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            }
    }
    int q;
    scanf("%d",&q);
    while(q--){
               int r1,c1,r2,c2,ans=0;
               scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
               if(r1<r2)ans+=a[r2-1][c2]+a[r1-1][c1-1]-a[r1-1][c2]-a[r2-1][c1-1];
               if(c1<c2)ans+=b[r2][c2-1]+b[r1-1][c1-1]-b[r1-1][c2-1]-b[r2][c1-1];
               printf("%d\n",ans);
    }
   // system("pause");
    return 0;
}