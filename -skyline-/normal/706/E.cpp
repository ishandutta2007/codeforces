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
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
int n,m,q,f[1200005],hx[1200005],hs[1200005],lx[1200005],ls[1200005];
int g[1005][1005],s;
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++)g[i][j]=++s;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf("%d",&f[g[i][j]]);
    }
    for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                    hx[g[i][j]]=g[i][j+1];
                    hs[g[i][j+1]]=g[i][j];
                    lx[g[i][j]]=g[i+1][j];
                    ls[g[i+1][j]]=g[i][j];
            }
    }
    for(int i=1;i<=q;i++){
            int a,b,c,d,h,w;
            scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h,&w);
            int x=g[a][0],y=g[c][0];
            for(int i=1;i<=b;i++)x=hx[x];
            for(int i=1;i<=d;i++)y=hx[y];
            for(int i=1;i<=h;i++){
                    swap(hs[x],hs[y]);      
                    hx[hs[x]]=x;
                    hx[hs[y]]=y;
                    x=lx[x];
                    y=lx[y];
            }
            x=ls[x];
            y=ls[y]; 
            for(int i=1;i<=w;i++){
                    swap(lx[x],lx[y]);
                    ls[lx[x]]=x;
                    ls[lx[y]]=y;
                    x=hx[x];
                    y=hx[y];
            }
            x=hs[x];
            y=hs[y];
            for(int i=1;i<=h;i++){
                    swap(hx[x],hx[y]);
                    hs[hx[x]]=x;
                    hs[hx[y]]=y;
                    x=ls[x];
                    y=ls[y];
            }
            x=lx[x];
            y=lx[y]; 
            for(int i=1;i<=w;i++){
                    swap(ls[x],ls[y]);
                    lx[ls[x]]=x;
                    lx[ls[y]]=y;
                    x=hs[x];
                    y=hs[y];
            }
    }
    for(int i=1;i<=n;i++){
            int x=hx[g[i][0]];
            for(int i=1;i<m;i++)printf("%d ",f[x]),x=hx[x];
            printf("%d\n",f[x]);
    }        
//	system("pause");

	return 0;
}