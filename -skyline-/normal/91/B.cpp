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
int n,a[120005],ans[120005],f[500];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+n+1-i);
    for(int i=1;i<=400;i++){
            f[i]=orz;
            for(int j=i*250-249;j<=i*250;j++)if(j<=n)f[i]=min(f[i],a[j]);
    }
    for(int i=1;i<=n;i++){
            int o=((i-1)/250)+1,p=-1;
            for(int j=1;j<o;j++)if(f[j]<a[i])p=j,j=o;
            if(p!=-1){
                      for(int j=p*250-249;j<=p*250;j++)if(a[j]<a[i])ans[n+1-i]=i-j-1,j=n;
                      continue;
            }
            for(int j=o*250-249;j<i;j++)if(a[j]<a[i])p=j,j=n;
            if(p==-1)ans[n+1-i]=-1;
            else ans[n+1-i]=i-p-1;
    }
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
//	system("pause");
	return 0;
}