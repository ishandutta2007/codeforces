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
ll f[2005][2005][2][2],a[2005],b[2005],m,d,x,y;
ll orz=1000000007;     
ll cty(int w,int r,int o,int p){
           if(w>x) return f[w][r][o][p]=(r==0);
           if(f[w][r][o][p]!=-1) return f[w][r][o][p];
           f[w][r][o][p]=0;
           if(w&1){
                   for(int i=0;i<=9;i++){
                           if(i==d) continue;
                           if(!((!o&&i<a[w])||(!p&&i>b[w])))
                           f[w][r][o][p]+=cty(w+1,(10*r+i)%m,o|(i>a[w]),p|(i<b[w]));
                   }
           }
           else if(!((!o&&d<a[w])||(!p&&d>b[w])))f[w][r][o][p]=cty(w+1,(10*r+d)%m,o|(d>a[w]),p|(d<b[w]));

           return (f[w][r][o][p]%=orz);
}
                   
int main()
{
    scanf("%I64d%I64d",&m,&d);
    char c=getchar();
    while(c=='\n')c=getchar();
    while(c!='\n')a[++x]=c-'0',c=getchar();
    while(c=='\n')c=getchar();
    while(c!='\n')b[++y]=c-'0',c=getchar();  
    for(int i=0;i<=2003;i++){
            for(int j=0;j<=2003;j++){
                    for(int k=0;k<=1;k++)f[i][j][k][0]=f[i][j][k][1]=-1;
            }
    }
    printf("%I64d\n",cty(1,0,0,0));
	//system("pause");
	return 0;
}