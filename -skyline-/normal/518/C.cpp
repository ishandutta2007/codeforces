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
long long n,m,k,a[100005];
long long ans;
map<long long,long long> b;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    for(int i=1;i<=n;i++){
            scanf("%I64d",a+i);
            b[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
            long long x,y,t;
            scanf("%I64d",&x);
            t=b[x];
            ans+=((t-1)/k)+1;
            if(t>1){
                        
                y=a[t-1];
                b[x]=b[y];
                b[y]=t;
                a[t]=y;
                a[t-1]=x;
            }
                
    }
    printf("%I64d\n",ans);                
   // system("pause");
    return 0;
}