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
int a,b,c,d,k,k0,k1,f[1000005],out[1000005];
int cty(ll hh){
    ll le=1,ri=1000000,ret=0;
    hh*=2ll;
    while(ri-le>1){
                   ll mi=(le+ri)/2ll;
                   if(mi*(mi-1ll)>hh)ri=mi;
                   else le=mi;
    }
    le--;
    ri++;
    if(le<1)le=1;
    for(ll i=le;i<=ri;i++)if(i*(i-1ll)==hh)ret=i;
    int ret2=ret;
    return ret2;
}
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a==0&&b==0&&c==0){
                         int k1=cty(d);
                         if(!k1) printf("Impossible\n");
                         else{
                              for(int i=1;i<=k1;i++)printf("1");
                              printf("\n");
                         }
                         return 0;
    }
    if(d==0&&b==0&&c==0){
                         int k0=cty(a);
                         if(!k0) printf("Impossible\n");
                         else{
                              for(int i=1;i<=k0;i++)printf("0");
                              printf("\n");
                         }
                         return 0;
    }
    ll hh=0;
    hh+=1ll*a;
    hh+=1ll*b;
    hh+=1ll*c;
    hh+=1ll*d;
    k=cty(hh);
    k0=cty(a);
    k1=cty(d);
    if(!k||!k0||!k1||k0+k1!=k){
           printf("Impossible\n");
           return 0;
    }
    for(int i=1;i<=k0;i++)f[i]=i;
    int o=k0;
    swap(b,c);
    while(b&&o){
                if(b>=k1)b-=k1,f[o]+=k1;
                else f[o]+=b,b=0;
                o--;
    }
    if(b){
          printf("Impossible\n");
          return 0;
    }
    for(int i=1;i<=k;i++)out[i]=1;
    for(int i=1;i<=k0;i++)out[f[i]]=0;
    for(int i=1;i<=k;i++)printf("%d",out[i]);
    printf("\n");
//	system("pause");
	return 0;
}