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
int n,m,a[100005],x,y;
vector<int> v[100005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            int f;
            scanf("%d",&f);
            v[f].push_back(i);
    }
    for(int i=1;i<=m;i++){
            int b;
            scanf("%d",&b);
            if(!v[b].size()){
                             x=1;
                             break;
            }
            if(v[b].size()>1){
                              y=1;
                              continue;
            }
            a[i]=v[b][0];
    }
    if(x)printf("Impossible\n");
    else if(y)printf("Ambiguity\n");
    else{
         printf("Possible\n");
         for(int i=1;i<m;i++)printf("%d ",a[i]);
         printf("%d\n",a[m]);
    }        
   // system("pause");
    return 0;
}