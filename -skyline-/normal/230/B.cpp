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
int main()
{
 	int n,i,j;
 	cin>>n;
 	bool a[1000010];
 	for(i=2;i<=1000005;i++)a[i]=1;
 	for(i=2;i<=1011;i++)if(a[i]==1)for(j=i*2;j<=1000005;j+=i)a[j]=0;
 	for(i=1;i<=n;i++){
					  long long x;
					  cin>>x;
					  long long c=sqrt(x);
					  cout<<((c*c==x&&a[c]==1)?"YES":"NO");
					  cout<<endl;
    }
					  
	//system("pause");
	//return 0;
}