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
int s,a[60][60],n,m,ci[200],c,u[60][60],f[60][60],now;
inline void ope(int x,int y){
       if(x<1||x>n||y<1||y>m) return;
       if(a[x][y]!=now) return;
       if(f[x][y]){
                   if(s-f[x][y]>2){
                                   cout<<"Yes"<<endl;
                                   exit(0);
                   }
                   return;
       }
       f[x][y]=++s;
       ope(x-1,y);
       ope(x,y-1);
       ope(x+1,y);                                   
       ope(x,y+1);                                   
       s--;
}
                                   
                                   
                                   
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    char cc;
                    cin>>cc;
                    if(ci[cc]) a[i][j]=ci[cc];
                    else a[i][j]=ci[cc]=++c;
            }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(u[i][j]) continue;
                    s=0;
                    memset(f,0,sizeof(f));
                    now=a[i][j];
                    ope(i,j);
            }
    }
    cout<<"No"<<endl;
   // system("pause");
    return 0;
}