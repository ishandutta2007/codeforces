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
char a[505][505];
char bz1[760000];
int bz2[760000],bz3[760000],v,m,n;
inline void ope(int i,int j,int x,int y)
{
    if(a[i][j]!='.'||i<1||j<1||i>m||j>n)return;
    v++;
    a[i][j]='B';
    bz1[v]='B';
    bz2[v]=i;
    bz3[v]=j;
    ope(i-1,j,i,j);
    ope(i+1,j,i,j);
    ope(i,j-1,i,j);
    ope(i,j+1,i,j);
    if(a[x][y]=='B')v++,a[i][j]='R',bz1[v]='D',bz2[v]=i,bz3[v]=j,v++,bz1[v]='R',bz2[v]=i,bz3[v]=j; 
}
int main()
{
    int i,j;
    cin>>m>>n;
    char c[505],x;
    for(i=1;i<=m;i++){
                      scanf("%s",&c);
                      for(j=1;j<=n;j++)a[i][j]=c[j-1];
    }
    a[0][0]='#';
    for(i=1;i<=m;i++)for(j=1;j<=n;j++)if(a[i][j]=='.')ope(i,j,0,0);
    printf("%d",v);
    puts("");
    for(i=1;i<=v;i++)printf("%c %d %d",bz1[i],bz2[i],bz3[i]),puts("");                
    //system("pause");
    //return 0;
}