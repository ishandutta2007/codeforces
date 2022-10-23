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
int n,m,a[105][105],s[105],o[105];
pair<int,int> p[105];
int ddd=1;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
            s[i]=1;
            for(int j=2;j<=n;j++)if(a[i][j]>a[i][s[i]])s[i]=j;     
            o[s[i]]--;
    }
    for(int i=1;i<=n;i++)p[i]=make_pair(o[i],i);
    sort(p+1,p+n+1);
    printf("%d\n",p[1].second);
   // system("pause");
    return 0;
}