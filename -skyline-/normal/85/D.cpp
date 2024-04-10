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
ll d[300015],q,n,x[100005],y[100005],u[100005],p[6][300005],w[300005];
map<ll,ll> m;
int main()
{
    for(ll i=1;i<=300003;i+=5)d[i]=1,d[i+1]=2,d[i+2]=3,d[i+3]=4;
    scanf("%I64d",&q);
    for(ll i=1;i<=q;i++){
            char c[10];
            scanf("%s",c);
            if(c[0]=='s') continue;
            x[i]=(c[0]=='a'?1:2);
            scanf("%I64d",y+i),u[i]=y[i];
    }
    sort(u+1,u+q+1);
    for(ll i=1;i<=q;i++)if(u[i]!=u[i-1]&&u[i])m[u[i]]=++n;
    for(ll i=1;i<=q;i++){
            if(x[i]){
                     ll t=m[y[i]]+131071;
                     w[t]^=1;
                     p[0][t]=(x[i]&1)?y[i]:0;
                     for(ll j=t>>1;j>=1;j>>=1){
                             ll l=j<<1,r=l^1;
                             w[j]=w[l]+w[r];
                             for(ll z=0;z<=4;z++)p[z][j]=p[z][l]+p[d[z+10-d[w[l]]]][r];
                     }
            }
            else printf("%I64d\n",p[2][1]);
    }
	//system("pause");
	return 0;
}