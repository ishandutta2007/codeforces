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
 	int l;
 	cin>>l;
 	string ss;
 	int k,i,a[3005];
 	char b[3005];
 	k=0;
 	cin>>ss;
 	for(i=1;i<=l;i++){
					  if(ss[i-1]!='.')k++,a[k]=i,b[k]=ss[i-1];
    }
	int s=0;
	if(k<2){
			 if(k==1)s=(b[1]=='R'?a[k]-1:l-a[k]);
			 cout<<(k==1?s:l)<<endl;
			 return 0;
    }
			 
	if(b[1]=='R')s+=(a[1]-1);
	if(b[k]=='L')s+=(l-a[k]);
	for(i=1;i<k;i++){
					 if(b[i]=='L'&&b[i+1]=='R')s+=(a[i+1]-1-a[i]);
					 if(b[i]=='R'&&b[i+1]=='L'&&(a[i+1]-a[i])%2==0)s++;
    }
	cout<<s<<endl;				 
	//system("pause");
	return 0;
}