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
using namespace std;
vector<int> v[30005];
int n,m,u[30005];
inline void ope(int x){
       u[x]=1;
       for(int i=0;i<v[x].size();i++)if(!u[v[x][i]])ope(v[x][i]);
       printf("%d ",x);
}
       
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
            if(!u[i])ope(i);
    }        
   // system("pause");
    return 0;
}