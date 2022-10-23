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
int n,a[200005],f[200005],ans;
int hh;
int cty(int x){return f[x]==x?x:f[x]=cty(f[x]);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),f[i]=i;
    for(int i=1;i<=n;i++){
            if(a[i]==i){
                        if(!hh)hh=i;
                        else ans++,a[i]=hh;
            }
    }
    for(int i=1;i<=n;i++){
            if(i==hh) continue;
            if(cty(i)==cty(a[i])){
                                  ans++;
                                  if(!hh)hh=i;
                                  a[i]=hh;
            }
            f[cty(i)]=cty(a[i]);
    }
    printf("%d\n",ans);
    for(int i=1;i<n;i++)printf("%d ",a[i]);
    printf("%d\n",a[n]);
//	system("pause");
	return 0;
}