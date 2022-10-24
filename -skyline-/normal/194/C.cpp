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
using namespace std;
int n,m,s,sum,h=1,hh=1,hhh=1,hhhh=1,ans;
char c[70][70];
bool u[70][70];
inline void ope(int x,int y){
       if(x<1||y<1||x>n||y>m||c[x][y]!='#'||u[x][y]) return;
       s++;
       u[x][y]=1;
       ope(x-1,y);
       ope(x,y-1);
       ope(x,y+1);
       ope(x+1,y);
}
       


inline bool ok(){
     s=0;
     memset(u,0,sizeof(u));
     if(c[h][hh]=='.')ope(hhh,hhhh);
     else ope(h,hh);
     return (s!=sum);
}
     

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                    cin>>c[i][j];
                    sum+=(c[i][j]=='#');
            }
    for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                    if(c[i][j]=='#'){                     
                                h=hhh;
                                hh=hhhh;
                                hhh=i;
                                hhhh=j;  
                    }
            }
    if(sum==1){
               puts("-1");
               return 0;
    }
               
    if(ok()){       
             puts("0");
             return 0;
    }
    ans=2;
    sum--;
    if(sum==1){
               puts("-1");
               return 0;
    }         
    for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                    if(c[i][j]=='.') continue;
                    c[i][j]='.';
                    if(ok()){
                             ans=1;
                             i=n+n;
                             break;
                    }
                    c[i][j]='#';
            }
    cout<<ans<<endl;
   // system("pause");
    return 0;
}