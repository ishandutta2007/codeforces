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
char c[10][10];
bool d[10][10][10];
int mx,my,ax,ay,aim;
queue<int> qx,qy,qt;
int main()
{
    for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                    cin>>c[i][j];
                    if(c[i][j]=='A')ax=i,ay=j;
                    if(c[i][j]=='M')mx=i,my=j;
                    if(c[i][j]=='S')d[2][i][j]=d[2][i+1][j]=1;
            }
    }
    for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                    if(d[2][i][j]){
                                   aim=9-i;
                                   i=9;
                                   break;
                    }
            }
    }
    for(int i=3;i<=aim;i++){
            for(int x=1;x<=8;x++){
                    for(int y=1;y<=8;y++)if(d[i-1][x-1][y])d[i][x][y]=1;
            }
    }
    qx.push(mx);
    qy.push(my);
    qt.push(1);
    while(!qt.empty()){
                      int x=qx.front(),y=qy.front(),t=qt.front();
                      qx.pop(),qy.pop(),qt.pop();
                      if(t==aim||(x==ax&&y==ay)){
                                                 puts("WIN");                                                                                                                                      
                                                 return 0;
                      }
                      t++;
                      for(int i=x-1;i<=x+1;i++){
                              for(int j=y-1;j<=y+1;j++){
                                      if(i>0&&j>0&&i<9&&j<9&&!d[t][i][j]){
                                                                          qx.push(i);
                                                                          qy.push(j);
                                                                          qt.push(t);
                                      }
                              }
                      }
    }
    puts("LOSE");
    return 0;
}