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
int a[22][2][200005],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            for(int j=0;j<=20;j++)(x&(1<<j))?(a[j][0][++a[j][0][0]]=i):(a[j][1][++a[j][1][0]]=i);
    }
    for(int i=1;i<=m;i++){
            int l,r,x,k=-1;
            scanf("%d%d%d",&l,&r,&x);
            for(int j=0;j<=20;j++){
                    if(x&(1<<j)){
                                 int o=*lower_bound(a[j][1]+1,a[j][1]+a[j][1][0]+1,l);
                                 if(o<=r&&a[j][1][0]&&o>=l)k=o,j=21;
                    }
                    else{
                         int o=*lower_bound(a[j][0]+1,a[j][0]+a[j][0][0]+1,l);
                         if(o<=r&&a[j][0][0]&&o>=l)k=o,j=21;
                    }
            }
            printf("%d\n",k);
    }
//	system("pause");
	return 0;
}