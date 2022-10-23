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
double d[2505][2505],f[2505][2505][2],ans;
ll x[2505],y[2505];
int t[5005],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)t[i]=t[i+n]=t[i+n+n]=i;
    for(int i=1;i<=n;i++)scanf("%I64d%I64d",x+i,y+i);
    for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                    double dx=x[i]-x[j],dy=y[i]-y[j];
                    d[i][j]=d[j][i]=sqrt(dx*dx+dy*dy);
            }
    }
    for(int i=1;i<=n;i++)f[i][t[i+1]][0]=f[i][t[i+1]][1]=d[i][t[i+1]];
    for(int l=2;l<=n-1;l++){
            for(int i=1;i<=n;i++){
                    f[i][t[i+l]][0]=d[i][t[i+l]]+max(f[t[i+1]][t[i+l]][1],d[t[i+l-1]][t[i+l]]+f[t[i+1]][t[i+l-1]][1]);
                    f[i][t[i+l]][1]=d[i][t[i+l]]+max(f[i][t[i+l-1]][0],d[i][t[i+1]]+f[t[i+1]][t[i+l-1]][0]);
            }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)ans=max(ans,max(f[i][j][0],f[i][j][1]));
    }
    printf("%.10lf\n",ans);
//	system("pause");
	return 0;
}