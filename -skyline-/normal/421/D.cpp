//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
using namespace std;
//
//
int n,p,x[300005],y[300005],f[300005],g[300005],s[300005];
ll ans;
map<pair<int,int>,int>m;
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++){
            scanf("%d%d",x+i,y+i);
            if(x[i]>y[i])swap(x[i],y[i]);
            m[mp(x[i],y[i])]++;
            f[x[i]]++,f[y[i]]++;
    }
    for(int i=1;i<=n;i++)g[f[i]]++;
    s[0]=g[0];
    for(int i=1;i<=n;i++)s[i]=s[i-1]+g[i];
    for(int i=0;i<=n;i++)ans+=1ll*g[i]*1ll*(s[n]-(i>=p?0:s[p-i-1]));
    for(int i=1;i<=n;i++)if(f[i]+f[i]>=p)ans--;
    for(int i=1;i<=n;i++){
            if(f[x[i]]+f[y[i]]<p) continue;
            if(f[x[i]]+f[y[i]]-m[mp(x[i],y[i])]<p){
                                                   m[mp(x[i],y[i])]=0;
                                                   ans-=2;
            }
    }
    printf("%I64d\n",ans/2ll);
//	system("pause");
	return 0;
}