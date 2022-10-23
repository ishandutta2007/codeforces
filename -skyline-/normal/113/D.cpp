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
#define pb   push_back
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//
int n,m,s1,s2;
double p[30][30],a[600][600];
vector<int> v[30];
int main()
{
    scanf("%d%d%d%d",&n,&m,&s1,&s2);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=n;i++){
            scanf("%lf",p[i]+i);
            double d=1.0-p[i][i];
            d/=1.0*v[i].size();
            for(int j=0;j<v[i].size();j++)p[i][v[i][j]]=d;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    a[i*n+j][i*n+j]-=1.0;
                    if(i==j) continue;
                    for(int k=1;k<=n;k++){
                            for(int l=1;l<=n;l++)a[k*n+l][i*n+j]+=p[i][k]*p[j][l];
                    }
            }
    }
    a[s1*n+s2][n*n+n+1]-=1.0;
    for(int i=n+1;i<=n*n+n;i++){
            int k=i;
            for(int j=i+1;j<=n*n+n;j++)if(abs(a[j][i])>abs(a[k][i])) k=j;
            for(int j=n+1;j<=n*n+n+1;j++)swap(a[i][j],a[k][j]);
            for(int j=i+1;j<=n*n+n+1;j++)a[i][j]/=a[i][i];
            for(int j=n+1;j<=n*n+n;j++){
                    if(i==j) continue;
                    for(int k=i+1;k<=n*n+n+1;k++)a[j][k]-=a[i][k]*a[j][i];
            }
    }
    for(int i=1;i<n;i++)printf("%.10lf ",a[i*n+i][n*n+n+1]);
    printf("%.10lf\n",a[n*n+n][n*n+n+1]);
	//system("pause");
	return 0;
}