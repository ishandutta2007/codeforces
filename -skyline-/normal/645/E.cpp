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
//I prefer being hacked than being FST
using namespace std;
int n,k,m,a[1000005];
ll ans=1,f[30],l[30];
pair<int,int> p[30];
int main()
{
    scanf("%d%d",&n,&k);
    char c=getchar();
    while(c=='\n')c=getchar();
    while(c!='\n')a[++m]=c-'a'+1,c=getchar();
    for(int i=1;i<=m;i++)l[a[i]]=i,ans=(ans-f[a[i]]+orz)%orz,f[a[i]]=(f[a[i]]+ans)%orz,ans=(ans+f[a[i]])%orz;
    for(int i=1;i<=k;i++)p[i]=mp(l[i],i);
    sort(p+1,p+k+1);
    p[0]=p[k];
    for(int i=1;i<=n;i++)ans=(ans-f[p[i%k].second]+orz)%orz,f[p[i%k].second]=(f[p[i%k].second]+ans)%orz,ans=(ans+f[p[i%k].second])%orz;
	printf("%I64d\n",ans);
  //  system("pause");
	return 0;
}