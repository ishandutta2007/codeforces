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
int n,m,w[600],a[1200],k[600],q[600],u[600],qs,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",w+i);
    for(int i=1;i<=m;i++){
            scanf("%d",a+i);
            if(!u[a[i]])q[++qs]=a[i],u[a[i]]=1;
    }
    for(int i=1;i<=m;i++){
            int s=1,l=a[i];
            while(q[s]!=a[i]){
                              k[q[s]]++;
                              swap(l,q[s]);
                              s++;
            }
            q[s]=l;
    }
    for(int i=1;i<=n;i++)ans+=k[i]*w[i];
    printf("%d\n",ans);                          
    //system("pause");
    return 0;
}