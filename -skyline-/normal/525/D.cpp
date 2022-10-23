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
int n,m;
queue<int>qx,qy;
char c[2005][2005];
bool ok(int x,int y){return (x&&y&&x<=n&&y<=m)&&c[x][y]=='*'&&((c[x-1][y-1]=='.'&&c[x-1][y]=='.'&&c[x][y-1]=='.')||(c[x+1][y-1]=='.'&&c[x+1][y]=='.'&&c[x][y-1]=='.')||(c[x-1][y+1]=='.'&&c[x-1][y]=='.'&&c[x][y+1]=='.')||(c[x+1][y+1]=='.'&&c[x+1][y]=='.'&&c[x][y+1]=='.'));}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=0;i<=n+1;i++)c[i][0]=c[i][m+1]='*';
    for(int i=0;i<=m+1;i++)c[0][i]=c[n+1][i]='*';
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)qx.push(i),qy.push(j);
    }
    while(!qx.empty()){
                       int x=qx.front(),y=qy.front();
                       qx.pop(),qy.pop();
                       if(!ok(x,y)) continue;
                       c[x][y]='.';
                       qx.push(x-1),qx.push(x-1),qx.push(x-1),qx.push(x),qx.push(x),qx.push(x+1),qx.push(x+1),qx.push(x+1),qy.push(y-1),qy.push(y),qy.push(y+1),qy.push(y-1),qy.push(y+1),qy.push(y-1),qy.push(y),qy.push(y+1);
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)printf("%c",c[i][j]);
            printf("\n");
    }
//	system("pause");
	return 0;
}