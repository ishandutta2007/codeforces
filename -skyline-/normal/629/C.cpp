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
int n,m,o,p,q;
ll c[2005][2005],orz=1000000007,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            char c;
            scanf(" %c",&c);
            if(c=='('){
                       o++;
                       p++;
            }
            else p--;
            q=min(p,q);
    }
    if(n&1){
            printf("0\n");
            return 0;
    }
    if(o>(n>>1)){
                 printf("0\n");
                 return 0;
    }
    c[0][0]=1;
    c[1][1]=1;
    for(int i=2;i<=2002;i++){
            for(int j=0;j<=i;j++){
                    c[i][j]=c[i-1][j-1]+c[i-1][j+1];
                    if(c[i][j]>orz)c[i][j]-=orz;
            }
    }
    q=-q;
    for(int i=0;i<=2002;i++){
            for(int j=q;j<=i;j++){
                    if(n-m-i<0||j+p>2002) continue;
                    ans+=c[i][j]*c[n-m-i][j+p];
                    ans%=orz;
            }
    }
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}