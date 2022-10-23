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
char c[2015][2015];
int a[2015][2015],n,m,sum;
queue<int> qx,qy;
inline void ope(int x,int y){
       a[x][y]--;                       
       if(a[x][y]==1)qx.push(x),qy.push(y);
}
       
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            scanf("%s",c[i]+1);
            for(int j=1;j<=m;j++)sum+=(c[i][j]=='.');
    }
    if(sum&1){
              puts("Not unique");
              return 0;
    }
    for(int i=1;i<=n;i++)c[i][0]=c[i][m+1]='*';
    for(int j=1;j<=m;j++)c[0][j]=c[n+1][j]='*';
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(c[i][j]=='*') continue;
                    a[i][j]+=c[i][j-1]+c[i-1][j]+c[i][j+1]+c[i+1][j]-168;
                    a[i][j]>>=2;
                    if(!a[i][j]){
                                 puts("Not unique");
                                 return 0;
                    }
                    if(a[i][j]==1)qx.push(i),qy.push(j);             
            }
    }
    while(!qx.empty()&&sum){
                       int x=qx.front(),y=qy.front(),xx,yy;
                       qx.pop();
                       qy.pop();
                       if(!a[x][y]||c[x][y]!='.') continue;
                       sum-=2;
                       if(c[x-1][y]=='.'){
                                          xx=x-1,yy=y;
                                          c[xx][y]='^';
                                          c[x][y]='v';
                                          ope(x-2,y);
                                          ope(xx,y-1);
                                          ope(xx,y+1);
                                          ope(x,y-1);
                                          ope(x,y+1);
                                          ope(x+1,y);
                       }                 
                       else if(c[x][y-1]=='.'){
                            xx=x,yy=y-1;
                            c[x][yy]='<';
                            c[x][y]='>';
                            ope(x,y-2);
                            ope(x-1,yy);
                            ope(x+1,yy);
                            ope(x-1,y);
                            ope(x+1,y);
                            ope(x,y+1);
                       }
                       else if(c[x+1][y]=='.'){
                            xx=x+1,yy=y;
                            c[xx][y]='v';
                            c[x][y]='^';
                            ope(x-1,y);
                            ope(x,y-1);
                            ope(x,y+1);
                            ope(xx,y-1);
                            ope(xx,y+1);
                            ope(x+2,y);
                       }
                       else{
                            xx=x,yy=y+1;
                            c[x][yy]='>';
                            c[x][y]='<';
                            ope(x,y-1);
                            ope(x-1,y);
                            ope(x+1,y);
                            ope(x-1,yy);
                            ope(x+1,yy);
                            ope(x,y+2);
                       }
                       //cout<<x<<y<<xx<<yy<<endl;
    }
    if(sum){
            puts("Not unique");
            //system("pause");
            return 0;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)printf("%c",c[i][j]);
            printf("\n");
    }
                                    
   // system("pause");
    return 0;
}