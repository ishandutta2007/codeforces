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
//:
using namespace std;
int n,ans[300007],m;
set<int> s;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)s.insert(i);
    s.insert(n+1);
    for(int i=1;i<=m;i++){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            set<int>::iterator it=s.lower_bound(l);
            for(;*it<=r;){               
                              if(*it==x) it++;
                              else{
                                   ans[*it]=x;
                                   s.erase(it++);
                              }
            }
    }
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);                        
	//system("pause");
	return 0;
}