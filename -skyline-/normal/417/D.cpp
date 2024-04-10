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
#define ll  long long
//:
using namespace std;
ll n,m,b,a[2000005],ans=1152921504606846976ll;
pair<ll,pair<ll,ll> >p[105];
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&b);
    for(int i=1;i<=n;i++){
            int o;
            scanf("%I64d%I64d%d",&p[i].second.first,&p[i].first,&o);
            for(int j=1;j<=o;j++){
                    int q=0;
                    scanf("%d",&q);
                    p[i].second.second|=1<<q;
            }
            p[i].second.second>>=1;
    }
    sort(p+1,p+n+1);
    m=1<<m;
    for(ll i=1;i<m;i++)a[i]=1152921504606846976ll;
    for(ll i=1;i<=n;i++){
            for(ll j=0;j<m;j++){
                    ll o=j|p[i].second.second;
                    a[o]=min(a[o],a[j]+p[i].second.first);
            }
            ans=min(ans,a[m-1]+p[i].first*b);
    }
    if(ans>=1152921504606846974ll)printf("-1\n");
    else printf("%I64d\n",ans);
	//system("pause");
	return 0;
}