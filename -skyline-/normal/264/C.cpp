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
int n,q,v[100005],c[100005],a,b,c1,c2;
ll g[100005],f[100005],m1,m2;
bool u[100005];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",v+i);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    for(int i=1;i<=q;i++){
            scanf("%d%d",&a,&b);
            memset(g,0,sizeof(g));
            memset(u,0,sizeof(u));
            m1=m2=0;
            c1=c2=0;
            for(int j=1;j<=n;j++){
                    f[j]=v[j]*1ll*b+((c1==c[j])?m2:m1);
                    if(u[c[j]])f[j]=max(f[j],v[j]*1ll*a+g[c[j]]);
                    if(!u[c[j]])u[c[j]]=1,g[c[j]]=f[j];
                    else g[c[j]]=max(g[c[j]],f[j]);
                    if(f[j]>=m1){
                                if(c[j]==c1)m1=f[j];
                                else m2=m1,c2=c1,m1=f[j],c1=c[j];
                    }
                    else if(f[j]>=m2&&c1!=c[j])m2=f[j],c2=c[j];
            }
            printf("%I64d\n",m1);
    }
//	system("pause");
	return 0;
}