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
int n,m,k,a[100005],x[100005],y[100005],z[100005],ans=orz;
bool b[100005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",x+i,y+i,z+i);
    for(int i=1;i<=n;i++)a[i]=orz;
    for(int i=1;i<=k;i++){
            int q;
            scanf("%d",&q);
            b[q]=1;
    }
    for(int i=1;i<=m;i++){
            if(b[x[i]]&&!b[y[i]])a[x[i]]=min(a[x[i]],z[i]);
            if(b[y[i]]&&!b[x[i]])a[y[i]]=min(a[y[i]],z[i]);
    }
    for(int i=1;i<=n;i++)ans=min(ans,a[i]);
    if(ans==orz)ans=-1;
    printf("%d\n",ans);
//	system("pause");
	return 0;
}