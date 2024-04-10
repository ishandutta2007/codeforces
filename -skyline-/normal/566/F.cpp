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
int n,a[1000005],b[1000005];
int main()
{
    scanf("%d",&n);
    int k,m=1;
    for(int i=1;i<=n;i++)scanf("%d",&k),b[k]++,m=max(m,k),a[k]++;
    for(int i=1;i<=m;i++){
            if(!b[i]) continue;
            for(int j=i+i;j<=1000002;j+=i)if(b[j])a[j]=max(a[j],a[i]+b[j]);
    }
    k=0;
    for(int i=1;i<=m;i++)k=max(k,a[i]);
    printf("%d\n",k);        
	//system("pause");
	return 0;
}