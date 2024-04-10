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
int n,q,ans,f[300005],a[300005],w[300005],r[300005],s,e;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==1)r[++s]=y,a[y]++,w[y]=s,ans++;
            else if(x==2) ans-=a[y],f[y]=w[y],a[y]=0;
            else{
                 for(;e<=y;e++)if(e>f[r[e]])f[r[e]]=e,a[r[e]]--,ans--;
            }
            printf("%d\n",ans);
    }
	//system("pause");
	return 0;
}