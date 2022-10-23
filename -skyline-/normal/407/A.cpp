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
int a[2000005];
vector<int>b[2000005];
vector<int>c[2000005];
int main()
{
 	int x,y,i,j;
 	cin>>x>>y;
	for(i=1;i<=1000;i++){
					   for(j=1;j<=1000;j++){
  						                  if(i==j){
										  		   continue;
					                      }
												   
					   					  a[i*i+j*j]++;
					   					  b[i*i+j*j].push_back(i);
					   					  c[i*i+j*j].push_back(j);
                       }
    }
    x=x*x;
    y=y*y;
	if(a[x]==0||a[y]==0){
						 cout<<"NO"<<endl;
						 return 0;
    }
	for(i=0;i<a[x];i++){
						 for(j=0;j<a[y];j++){
						 					  c[y][j]=-c[y][j];
											  if((b[x][i]*b[y][j]+c[x][i]*c[y][j])==0){
											  										   if(b[x][i]==b[y][j]||c[y][j]==c[x][i])b[y][j]*=-1,c[y][j]*=-1;
											  										   cout<<"YES"<<endl;
											  										   cout<<0<<' '<<0<<endl;
																					   cout<<b[x][i]<<' '<<c[x][i]<<endl;
																					   cout<<b[y][j]<<' '<<c[y][j]<<endl;
																					   //system("pause");
																					   return 0;
										      }
					     }
    }
	cout<<"NO"<<endl;					  
	//system("pause");
	return 0;
}