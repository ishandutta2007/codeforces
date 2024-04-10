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
int n,k,a[5002];
map<int,int> m;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            for(int j=1;j<=k;j++){
                    if(m.count(a[i]*j))m[a[i]*j]=min(m[a[i]*j],j);
                    else m[a[i]*j]=j;
            }
    }
    m[0]=0;
    int q;
    scanf("%d",&q);
    while(q--){
               int t,ans=k+1;
               scanf("%d",&t);
               for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
                                          int f=(*i).first,s=(*i).second;
                                          if(t<f) break;
                                          if(m.count(t-f))ans=min(ans,s+m[t-f]);
               }
               if(ans==k+1)ans=-1;                                                                                                                                                       
               printf("%d\n",ans);
    }
	//system("pause");
	return 0;
}