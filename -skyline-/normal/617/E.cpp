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
#define X   first
#define Y   second
//:
using namespace std;
int n,m,k,a[100005],c[2000005],l=1,r;
ll ans[100005],s;
pair<pair<int,int>,pair<int,int> >p[100005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n+1;i++)scanf("%d",a+i),a[i]^=a[i-1];
    for(int i=1;i<=m;i++)scanf("%d%d",&p[i].Y.X,&p[i].X.Y),p[i].X.X=((p[i].Y.X)/350)+1,p[i].X.Y++,p[i].Y.Y=i;
    sort(p+1,p+m+1);
    for(int i=1;i<=m;i++){
            int o=p[i].Y.X,q=p[i].X.Y;
            while(r<q)c[a[++r]]++,s+=c[a[r]^k];
            while(l>o)c[a[--l]]++,s+=c[a[l]^k];
            while(r>q)s-=c[a[r]^k],c[a[r--]]--;
            while(l<o)s-=c[a[l]^k],c[a[l++]]--;
            ans[p[i].Y.Y]=s;
    }
    if(!k)for(int i=1;i<=m;i++)ans[p[i].Y.Y]-=(ll)(1ll+p[i].X.Y-p[i].Y.X);
    for(int i=1;i<=m;i++)printf("%I64d\n",ans[i]);
	//system("pause");
	return 0;
}