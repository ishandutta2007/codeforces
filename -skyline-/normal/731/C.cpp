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
int n,m,k,c[200005],f[200005],q[200005],ans;
vector<int> v[200005];
int cty(int x){return f[x]==x?x:f[x]=cty(f[x]);}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%d",c+i),f[i]=i;
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(cty(x)!=cty(y))f[f[x]]=f[y];
    }
    for(int i=1;i<=n;i++)v[cty(i)].pb(i);
    ans=n;
    for(int i=1;i<=n;i++){
            int o=0;
            for(int j=0;j<v[i].size();j++)q[c[v[i][j]]]++,o=max(q[c[v[i][j]]],o);
            ans-=o;
            for(int j=0;j<v[i].size();j++)q[c[v[i][j]]]--;
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}