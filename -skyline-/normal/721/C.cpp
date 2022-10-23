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
//
int a[5005][5005],p[5005][5005],n,m,t;
vector<int> x[5005],y[5005],z[5005],res;
bool b[5005];
void cty(int k){
     if(b[k]) return;
     b[k]=1;
     for(int i=0;i<z[k].size();i++)cty(z[k][i]);
     res.pb(k);
}
void prt(int x,int y){
     if(x!=1)prt(p[x][y]/10000,p[x][y]%10000);
     printf("%d ",x);
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=m;i++){
            int q,w,e;
            scanf("%d%d%d",&q,&w,&e);
            x[q].pb(w),y[q].pb(e),z[w].pb(q);
    }
    for(int i=1;i<=n;i++)if(!b[i])cty(i);
    memset(a,-1,sizeof(a));
    a[1][1]=0;
    for(int i=0;i<n;i++){
            int k=res[i];
            for(int j=1;j<=n;j++){
                    if(a[k][j]==-1) continue;
                    for(int l=0;l<x[k].size();l++){
                            int o=y[k][l]+a[k][j];
                            if(o>t) continue;
                            if(a[x[k][l]][j+1]==-1||o<a[x[k][l]][j+1])a[x[k][l]][j+1]=o,p[x[k][l]][j+1]=k*10000+j;
                    }
            }
    }
    int ans=n;
    while(a[n][ans]==-1)ans--;
    printf("%d\n",ans);
    prt(n,ans);
//	system("pause");
	return 0;
}