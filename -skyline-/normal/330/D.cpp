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
queue<int> qx,qy;
int n,m,k=2147483640,a[1005][1005],d[1005][1005],ans,z;
char c[1005][1005];
void ok(int x,int y){if(x>0&&y>0&&x<=n&&y<=m&&d[x][y]==-1)d[x][y]=z,qx.push(x),qy.push(y);};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    int tx,ty;
    memset(d,-1,sizeof(d));
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(c[i][j]=='E')tx=i,ty=j;
                    if(c[i][j]=='S')a[i][j]=-1;
                    else if(c[i][j]>=48&&c[i][j]<58)a[i][j]=c[i][j]-48;
                    else d[i][j]=0;
            }
    }
    qx.push(tx),qy.push(ty);
    while(!qx.empty()){
                      int x=qx.front(),y=qy.front();
                      if(d[x][y]>k) break;
                      qx.pop(),qy.pop();
                      if(a[x][y]==-1) k=d[x][y];
                      else ans+=a[x][y];
                      z=d[x][y]+1;
                      ok(x-1,y),ok(x,y-1),ok(x,y+1),ok(x+1,y);
    }
    printf("%d\n",ans);
	//system("pause");
	return 0;
}