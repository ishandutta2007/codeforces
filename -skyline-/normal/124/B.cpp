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
int n,k,v[12],u[12];
char a[12][12];
int x1=2147483646;
inline int js(int s){
	int i,j;
    int t=0;
	for(j=0;j<k;j++)t=t*10+(a[s][v[j]]-'0');
	return t;
}
void qpl(int h){
	            int i,j;
				int minx=2147483646;
   	            int maxx=-1;
   	            if(h==(k-1)){
								 
						for(i=1;i<=n;i++){
										  int t=js(i);
										  maxx=max(maxx,t);
										  minx=min(minx,t);
					    }
						x1=min(x1,maxx-minx);
						return;
				}
						
				for(i=0;i<k;i++){
								 if(u[i]==1){
								 			 continue;
								 }
								 u[i]=1,v[h+1]=i,qpl(h+1),u[i]=0;
			    }
}
								 
				
int main()
{
 	cin>>n>>k;
 	int i,j;
 	for(i=1;i<=n;i++)cin>>a[i];
 	for(i=0;i<k;i++){
					 u[i]=1;
					 v[0]=i;
 	                 qpl(0);
 	                 u[i]=0;
    }
					 
	cout<<x1<<endl;
	//system("pause");
	return 0;
}