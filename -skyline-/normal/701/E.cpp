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
int n,k,K,a[200005],o[200005],d[200005];
vector<int> v[200005];
bool b[200005];
void cty(int x,int p){
     if(b[x]) o[x]=1;
     for(int i=0;i<v[x].size();i++){
             if(p==v[x][i]) continue;
             d[v[x][i]]=d[x]+1;
             cty(v[x][i],x);
             o[x]+=o[v[x][i]];
     }
}
ll dtx(int x,int p,int q){
           int h=0,l=0;
           for(int i=0;i<v[x].size();i++){
                   if(p==v[x][i]) continue;
                   if(o[v[x][i]]>=h)h=o[v[x][i]],l=i;
           }
           if(q-o[x]+h<=o[x]-h) return 1ll*d[x]*1ll*q;
           return dtx(v[x][l],x,q-o[x]+h-o[x]+h)+1ll*d[x]*2ll*(o[x]-h);
}
           
int main()
{
    scanf("%d%d",&n,&k);
    K=k<<1;
    for(int i=1;i<=K;i++)scanf("%d",a+i),b[a[i]]=1;
    for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
    }
    cty(1,0);
    ll ans=0;
    for(int i=1;i<=K;i++)ans+=1ll*d[a[i]];
    printf("%I64d\n",ans-dtx(1,0,K));
//	system("pause");
	return 0;
}