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
//:
using namespace std;
//
//
char s[1005],t[1005];
int n,m,f[1005][1005];
void cty(int x,int y){
     if(x==0&&y==0) return;
     if(x&&y&&s[x]==t[y]){              
                          cty(x-1,y-1);
                          return;     
     }
     if(x&&f[x-1][y]+1==f[x][y]){                           
                               printf("DELETE %d\n",x);
                               cty(x-1,y);               
                               return;
     }
     if(y&&f[x][y-1]+1==f[x][y]){                                               
                               printf("INSERT %d %c\n",x+1,t[y]);
                               cty(x,y-1);                 
                               return;
     } 
     printf("REPLACE %d %c\n",x,t[y]);                             
     cty(x-1,y-1);
}
              
int main()
{
    char c=getchar();
    while(c!='\n')s[++n]=c,c=getchar();
    c=getchar();
    while(c!='\n')t[++m]=c,c=getchar();
    for(int i=1;i<=n;i++)f[i][0]=i;
    for(int i=1;i<=m;i++)f[0][i]=i;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    f[i][j]=min(min(f[i][j-1]+1,f[i-1][j]+1),f[i-1][j-1]+(s[i]!=t[j]));
            }
    }
    printf("%d\n",f[n][m]);
    cty(n,m);
	//system("pause");
	return 0;
}