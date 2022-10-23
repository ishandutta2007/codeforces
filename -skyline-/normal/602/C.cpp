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
bool k,f[405][405];
int n,m,a[405];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            f[x][y]=f[y][x]=1;
    }
    if(!f[1][n])k=1;
    memset(a,-1,sizeof(a));
    a[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
                      int o=q.front();
                      q.pop();
                      for(int i=2;i<=n;i++)if(a[i]==-1&&f[i][o]==k)a[i]=a[o]+1,q.push(i);
    }
    printf("%d\n",a[n]);
  //  system("pause");
    return 0;
}