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
#include<Windows.h>
using namespace std;
int n,a[200000],i,j,k,l;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    
    for(i=2;i<=n;i++){
                      if(a[i]<a[i-1])l=i,k++;
    }
    if(k>1||(k==1&&a[1]<a[n]))cout<<-1<<endl;
    else if(k==1)cout<<n-l+1<<endl;
    else cout<<0<<endl;   
                               
	//system("pause");
	return 0;
}