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
//:
using namespace std;
ll n,xx,yy,x2,y2,x[2005],y[2005],ans;
pair<ll,ll> p[2005];
multiset<ll> s;
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&xx,&yy,&x2,&y2);
    for(int i=1;i<=n;i++){
            scanf("%I64d%I64d",x+i,y+i);
            p[i]=make_pair((x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy),(x[i]-x2)*(x[i]-x2)+(y[i]-y2)*(y[i]-y2));
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)s.insert(-p[i].second);
    ans=min(-(*s.begin()),p[n].first);
    for(int i=1;i<=n;i++){
            s.erase(s.find(-p[i].second));
            ans=min(ans,p[i].first-(*s.begin()));
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}