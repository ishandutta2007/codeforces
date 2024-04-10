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
#include<Windows.h>
using namespace std;
int n,m,t,p,u,d,a[320][320],f[4][320][320],i,j,k,l;
inline int absn(int x){
       return (x<0?-x:x);
}

inline  int pud(int x,int y){
        if(x==y)return p;
        return (x>y?d:u);
}

void fmake(){
     for(i=1;i<=n;i++){
                      for(j=1;j<m;j++){
                                       f[0][i][j]=f[0][i][j-1]+pud(a[i][j],a[i][j+1]);
                      }
     }
     for(i=1;i<n;i++){
                      for(j=1;j<=m;j++){
                                       f[2][i][j]=f[2][i-1][j]+pud(a[i][j],a[i+1][j]);
                      }
     }
     for(i=1;i<=n;i++){
                      for(j=m-1;j>0;j--){
                                       f[1][i][j]=f[1][i][j+1]+pud(a[i][j+1],a[i][j]);
                      }
     }
     for(i=n-1;i>0;i--){
                      for(j=1;j<=m;j++){
                                       f[3][i][j]=f[3][i+1][j]+pud(a[i+1][j],a[i][j]);
                      }
     }
     return;
}
                     
                                         
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d",&p,&u,&d);
    for(i=1;i<=n;i++){
                      for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
    }
    fmake();
    int minx=2147483640,x1=-1,y1=-1,x2=-1,y2=-1;
    for(i=1;i<n-1;i++){
                       for(j=1;j<m-1;j++){
                                          for(k=i+2;k<=n;k++){
                                                              for(l=j+2;l<=m;l++){
                                                                                  int ans=absn((f[0][i][l-1]-f[0][i][j-1])+(f[1][k][j]-f[1][k][l])+(f[2][k-1][l]-f[2][i-1][l])+(f[3][i][j]-f[3][k][j])-t);
                                                                                  if(ans<minx)minx=ans,x1=i,x2=k,y1=j,y2=l;
                                                              }
                                          }
                       }
    }
    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;                                               //  //         
   // system("pause");
    return 0;
}