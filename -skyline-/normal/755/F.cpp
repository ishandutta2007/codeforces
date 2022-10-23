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
int n,f[1000005],a[1000005],c[1000005],q[1000005],s,k,d[1000005];
int cty(int x){return x==f[x]?x:f[x]=cty(f[x]);}
bitset<1000005> b;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i),f[i]=i;
    for(int i=1;i<=n;i++)if(cty(a[i])!=cty(i))f[f[i]]=f[a[i]];
    for(int i=1;i<=n;i++)f[i]=cty(i);
    for(int i=1;i<=n;i++)c[f[i]]++;
    for(int i=1;i<=n;i++)if(f[i]==i)q[++s]=c[i];
    sort(q+1,q+s+1);
    int cnt[2]={};
    for(int i=1;i<=s;i++){
            cnt[0]+=q[i]>>1;
            if(q[i]&1)cnt[1]++;
            d[q[i]]++;
    }
    int ans1,ans2;
    if(k<=cnt[0])ans2=k<<1;
    else ans2=min(n,k+cnt[0]);
    b[0]=1;
    for(int i=1;i<=n;i++){
            if(!d[i]) continue;
            for(int j=1;j<=d[i];d[i]-=j,j<<=1)b|=b<<(i*j);
            b|=b<<(i*d[i]);
    }
    ans1=b[k]?k:k+1;
    printf("%d %d\n",ans1,ans2);
//	system("pause");
	return 0;
}