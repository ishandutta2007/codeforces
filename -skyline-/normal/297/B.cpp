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
 	int n,m,k;
	cin>>n>>m>>k;
	int a[100005],b[100005];
	int i;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(n>m){
			cout<<"YES"<<endl;
			return 0;
	}
	reverse(a+1,a+n+1);
	reverse(b+1,b+m+1);		
	for(i=1;i<=n;i++){
					 if(b[i]<a[i]){
					 			   cout<<"YES"<<endl;
					 			   return 0;
			         }
    }
	cout<<"NO"<<endl;				 
								   
	//system("pause");
	return 0;
}