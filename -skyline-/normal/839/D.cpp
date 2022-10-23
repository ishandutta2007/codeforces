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
#define orz  1000000007ll
//:
using namespace std;
//
//
int c[1000005],f[1000005],n;
ll b[1000005];
int main()
{
    for(int i=2;i<=1000000;i++)c[i]=i;
    for(int i=2;i<=1000000;i++){
            for(int j=i+i;j<=1000000;j+=i)c[j]-=c[i];
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x==1) continue;
            for(int i=1;i*i<=x;i++){
                    if(i*i==x)f[i]++;
                    else if(x%i==0)f[i]++,f[x/i]++;
            }
    }
    b[0]=1;
    ll ans=0;
    for(int i=1;i<=n;i++)b[i]=(b[i-1]*2ll)%orz;
    for(int i=2;i<=1000000;i++){
            if(!f[i]) continue;
            ll p=b[f[i]-1]*(f[i]*1ll);
            p%=orz;
            p*=(c[i]*1ll);
            p%=orz;
            ans+=p;
            ans%=orz;
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}