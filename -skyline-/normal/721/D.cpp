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
ll n,k,x,a[200005],q,w;
set<pair<ll,ll> > s;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&k,&x);
    for(ll i=1;i<=n;i++){
            scanf("%I64d",a+i);
            if(a[i]==0)w++;
            if(a[i]<0)q++;
    }
    if(w>k){
            for(ll i=1;i<=n;i++)if(k&&a[i]==0)a[i]+=x,k--;
            for(ll i=1;i<n;i++)printf("%I64d ",a[i]);
            printf("%I64d\n",a[n]);
            return 0;
    }
    if(w){                                             
          k-=w;        
          if(q&1){
                  for(ll i=1;i<=n;i++)if(!a[i])a[i]+=x;
          }
          else{
               bool bbb=1;
               q++;
               for(ll i=1;i<=n;i++){
                       if(!a[i]){
                                 if(bbb)bbb=0,a[i]=-x;
                                 else a[i]=x;
                       }
               }
          }
    }
    for(ll i=1;i<=n;i++)s.insert(mp(abs(a[i]),i));
    for(ll i=1;i<=k;i++){
            ll o=s.begin()->second;
            s.erase(s.begin());
            if(q&1){
                    if(a[o]<0)a[o]-=x;
                    else a[o]+=x;
            }
            else{
                 ll t=a[o];
                 if(a[o]<0)a[o]+=x;
                 else a[o]-=x;
                 if(t<0&&a[o]>=0)q--;
                 if(t>=0&&a[o]<0)q++; 
            }
            s.insert(mp(abs(a[o]),o));
    }
    for(ll i=1;i<n;i++)printf("%I64d ",a[i]);
    printf("%I64d\n",a[n]);
//	system("pause");
	return 0;
}