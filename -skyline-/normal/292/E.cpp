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
int a[200005],n,m,o[100005],f[400005];
void cty(int x,int y,int z,int l,int r,int k){
     if(l>=x&&r<=y){
                    f[k]=z;
                    return;
     }
     int m=(l+r)>>1;
     if(x<=m)cty(x,y,z,l,m,k<<1);
     if(y>m)cty(x,y,z,m+1,r,(k<<1)^1);
}               
int main()
{
    scanf("%d%d",&n,&m);
    n<<=1;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    n>>=1;
    o[0]=n;
    for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            if(x==2){
                     int t,ans=0;
                     scanf("%d",&t);
                     int T=t;
                     t+=131071;
                     while(t){
                              ans=max(ans,f[t]);
                              t>>=1;
                     }
                     printf("%d\n",a[T+o[ans]]);
                     continue;
            }
            int y,u;
            scanf("%d%d%d",&x,&y,&u);
            o[i]=x-y;
            cty(y,y+u-1,i,1,131072,1);
    }
	//system("pause");
	return 0;
}