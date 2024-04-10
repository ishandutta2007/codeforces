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
int n,m;
ll a[100015],b[100015],c[100015],d[100015],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%I64d",a+i);
    for(int j=1;j<=m;j++)scanf("%I64d",b+j);
    b[0]=-orz*1ll-orz*1ll-orz*1ll;
    b[m+1]=orz*1ll+orz*1ll+orz*1ll;
    d[n+1]=m+1;
    for(int i=1;i<=n;i++){
            c[i]=c[i-1];
            while(b[c[i]+1]<=a[i])c[i]++;
    }
    for(int i=n;i;i--){
            d[i]=d[i+1];
            while(b[d[i]-1]>=a[i])d[i]--;
    }
    for(int i=1;i<=n;i++)ans=max(ans,min(1ll*a[i]-1ll*b[c[i]],1ll*b[d[i]]-1ll*a[i]));
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}