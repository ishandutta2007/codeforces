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
int n,m,a[100005];
vector<int> ans[2],v[100005];
bool cty(int x,int k,int p){
     if(a[x]==(k^1)) return 0;
     if(a[x]==k) return 1;
     a[x]=k;
     ans[k].pb(x);
     bool ok=1;
     for(int i=0;i<v[x].size();i++)if(v[x][i]!=p)ok&=cty(v[x][i],k^1,x);
     return ok;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y),v[y].pb(x);
    }
    memset(a,-1,sizeof(a));
    bool ok=1;
    for(int i=1;i<=n;i++)if(a[i]==-1)ok&=cty(i,0,-1);
    if(!ok)printf("-1\n");
    else{
         printf("%d\n%d",ans[0].size(),ans[0][0]);
         if(ans[0].size()>1)for(int i=1;i<ans[0].size();i++)printf(" %d",ans[0][i]);
         printf("\n%d\n%d",ans[1].size(),ans[1][0]);
         if(ans[1].size()>1)for(int i=1;i<ans[1].size();i++)printf(" %d",ans[1][i]);
         printf("\n");
    }
//	system("pause");
	return 0;
}