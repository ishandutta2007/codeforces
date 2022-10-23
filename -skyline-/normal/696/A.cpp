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
int q;
ll ans;
map<ll,ll> m;
ll cty(ll x,ll y){
          while(x!=y){
                      if(x<y)y>>=1;
                      else x>>=1;
          }
          return x;
}
int main()
{
    scanf("%d",&q);
    while(q--){
               int t;
               scanf("%d",&t);
               if(t==1){
                        ll x,y,z;
                        scanf("%I64d%I64d%I64d",&x,&y,&z);
                        if(x>y) swap(x,y);
                        if(x==y) continue;
                        ll w=cty(x,y);
                        if(w==x) while(y!=w)m[y]+=z,y>>=1;
                        else{
                             while(y!=w)m[y]+=z,y>>=1;
                             while(x!=w)m[x]+=z,x>>=1;
                        }
               }
               else{
                    ll x,y;
                    scanf("%I64d%I64d",&x,&y);
                    if(x>y) swap(x,y);
                    if(x==y){
                             printf("0\n");
                             continue;
                    }
                    ll w=cty(x,y);
                    if(w==x){
                             ans=0;
                             x=y;
                             while(x!=w){
                                         if(m.count(x))ans+=m[x];
                                         x>>=1;
                             }
                             printf("%I64d\n",ans);
                    }
                    else{
                         ans=0;   
                         while(x!=w){
                                     if(m.count(x))ans+=m[x];
                                     x>>=1;
                         }   
                         x=y;                 
                         while(x!=w){
                                     if(m.count(x))ans+=m[x];
                                     x>>=1;
                         }  
                         printf("%I64d\n",ans);  
                    } 
               } 
    }      
//	system("pause");
	return 0;
}