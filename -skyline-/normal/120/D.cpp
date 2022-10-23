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
int n,m,a[60][60],r[60],c[60],p[5],ans;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    scanf("%d",&a[i][j]);
                    r[i]+=a[i][j];
                    c[j]+=a[i][j];
            }
    }
    for(int i=2;i<=n;i++)r[i]+=r[i-1];
    for(int i=2;i<=m;i++)c[i]+=c[i-1];
    scanf("%d%d%d",p+1,p+2,p+3);
    sort(p+1,p+4);
    if(p[1]+p[2]+p[3]!=r[n]){
                             printf("0\n");
                             return 0;
    }
    do{
          for(int r1=1;r1<=n-2;r1++){
                  for(int r2=r1+1;r2<=n-1;r2++){
                          if(r[r1]==p[1]&&r[r2]-r[r1]==p[2]) ans++;
                  }
          }
          for(int c1=1;c1<=m-2;c1++){
                  for(int c2=c1+1;c2<=m-1;c2++){
                          if(c[c1]==p[1]&&c[c2]-c[c1]==p[2]) ans++;
                  }
          }
    }while(next_permutation(p+1,p+4));
    printf("%d\n",ans);
   // system("pause");
    return 0;
}