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
int n,m,la=-1;
ll c[100005],ans,sum,o;
bool b[100005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            scanf("%I64d",c+i);
            sum+=c[i];
    }
    c[0]=c[n];
    c[n+1]=c[1];
    for(int i=1;i<=n;i++)ans+=c[i]*c[i-1];
    for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            b[x]=1;
            ans-=c[x]*(c[x-1]+c[x]+c[x+1]);
            ans+=c[x]*sum;
            ans-=o*c[x];
            if(la==x-1)ans+=c[x]*c[x-1];
            o+=c[x];
            la=x;
    }
    if(b[1]&&b[n])ans+=c[1]*c[n];
    printf("%I64d\n",ans);
  //	system("pause");
	return 0;
}