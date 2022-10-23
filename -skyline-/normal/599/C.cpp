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
pair<int,int> p[100005],q[200005];
int n,a[100005],ans,k,s[100005],b[100005];
map<int,int> m;
int ope(int x){return x==a[x]?x:a[x]=ope(a[x]);};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%d",&p[i].first);
            p[i].second=a[i]=i;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++){
            if(ope(i)!=ope(p[i].second))a[a[i]]=a[p[i].second];
    }
    for(int i=1;i<=n;i++){
            if(!m.count(ope(i)))m[a[i]]=++k,s[k]=i,b[k]=i;
            else{
                 int o=m[a[i]];
                 s[o]=min(s[o],i);
                 b[o]=max(b[o],i);
            }
    }
    for(int i=1;i<=k;i++)q[i]=make_pair(s[i],-1),q[i+k]=make_pair(b[i],1);
    sort(q+1,q+k+k+1);
    int res=0;
    for(int i=1;i<=k+k;i++)res+=q[i].second,ans+=(res==0);       
    printf("%d\n",ans);
 //   system("pause");
    return 0;
}