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
#define pb   push_back
//:
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int a[100005],n,T,p,q,s,t[300005];
vector<int> v[100005];
map<int,int> m;
int cty(int l,int r,int k){
           if(l>q||r<p) return 0;
           if(p<=l&&r<=q) return t[k];
           int o=(l+r)>>1,lc=cty(l,o,k<<1),rc=cty(o+1,r,(k<<1)+1);
           return lc&&rc?__gcd(lc,rc):lc+rc;
}
int dtx(int o,int t){
    int r=v[o].size()-1,l=0;
    if(v[o][0]>t) return -1;
    if(v[o][r]<=t) return r;
    while(r-l>1){
                 int x=(l+r)>>1;
                 if(v[o][x]>t)r=x;
                 else l=x;
    }
    while(l+1<v[o].size()&&v[o][l+1]<=t)l++;
    while(l&&v[o][l]>t)l--;
    return l;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),t[i+131071]=a[i],v[m[a[i]]?m[a[i]]:m[a[i]]=++s].pb(i);
    for(int i=n+131072;i<262144;i++)t[i]=1;
    for(int i=131071;i;i--)t[i]=(t[i<<1]&&t[(i<<1)^1])?__gcd(t[i<<1],t[(i<<1)^1]):t[i<<1]+t[(i<<1)^1];
    scanf("%d",&T);
    while(T--){
               scanf("%d%d",&p,&q);
               int o=(int)cty(1,131072,1),ans=0;
               if(m.count(o))o=m[o],ans=dtx(o,q)-dtx(o,p-1);
               printf("%d\n",q-p+1-ans);
    }
//	system("pause");
	return 0;
}