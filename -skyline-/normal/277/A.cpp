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
int n,m,a[200],ans;
bool b;
vector<int> v[200];
inline int ope(int x){return x==a[x]?x:a[x]=ope(a[x]);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            a[i]=i;
            int k;
            scanf("%d",&k);
            b+=k;
            for(int j=1;j<=k;j++){
                    int x;
                    scanf("%d",&x);
                    v[x].push_back(i);
            }
    }
    for(int i=1;i<=m;i++){
            for(int j=1;j<v[i].size();j++)a[ope(v[i][j])]=ope(v[i][0]);
    }
    for(int i=1;i<=n;i++)ans+=(a[i]==i);
    printf("%d\n",ans-b);                             
	//system("pause");
	return 0;
}