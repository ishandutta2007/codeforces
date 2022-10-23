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
int n;
char a[1005][1005];
inline int js(){
	   int s;
	   for(int i=0;i<n;i++)s+=a[i][i];
	   s=s%2;
	   return s;
}
	   
int main()
{
 	cin>>n;
 	int i,j;
 	for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%s",&a[i][j]);
 	int q;
 	int ans=js();
 	scanf("%d",&q);
 	for(i=1;i<=q;i++){
					  int v;
					  scanf("%d",&v);
					  if(v==3)printf("%d",ans);
					  else{
					  	   int t;
					  	   scanf("%d",&t);
					  	   ans^=1;
				      }
    }					   
	//system("pause");
	return 0;
}