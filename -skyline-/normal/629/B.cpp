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
int n,x[400],y[400],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            char c;
            int a,b;
            scanf(" %c%d%d",&c,&a,&b);
            if(c=='M')x[a]++,x[b+1]--;
            else y[a]++,y[b+1]--;
    }
    for(int i=1;i<=370;i++){
            x[i]+=x[i-1];
            y[i]+=y[i-1];
            ans=max(ans,min(x[i],y[i]));
    }
    printf("%d\n",ans<<1);
//	system("pause");
	return 0;
}