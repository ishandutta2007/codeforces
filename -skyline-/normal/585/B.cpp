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
int t,a[5][112],sx,sy,n,k;
char c[5][117];
int main()
{
    scanf("%d",&t);
    while(t--){
               memset(a,0,sizeof(a));
               scanf("%d%d",&n,&k);
               for(int i=1;i<=3;i++){
                       for(int j=1;j<=n;j++){
                               scanf(" %c",c[i]+j);
                               if(c[i][j]=='s')sx=i,sy=j,c[i][j]='.';
                       }
               }
               for(int i=1;i<=3;i++)for(int j=n+1;j<=n+5;j++)a[i][j]=1,c[i][j]='.';
               for(int i=n+5;i-3>=0;i--){
                       if(i<sy) break;
                       for(int j=1;j<=3;j++){
                               if(a[j][i]&&c[j][i-3]=='.'&&c[j][i-2]=='.'&&c[j][i-1]=='.'){
                                           if(c[j-1][i-3]=='.')a[j-1][i-3]=1;
                                           if(c[j+1][i-3]=='.')a[j+1][i-3]=1;
                                           a[j][i-3]=1;
                               }          
                       }
               }
               if(a[sx][sy+1]){
                               printf("YES\n");
               }
               else printf("NO\n");
    }        
	//system("pause");
	return 0;
}