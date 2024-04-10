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
double a,d,aa,dd;
int main()
{
 	int i,n;
 	//scanf("%1f %1f",&a,&d);
 	//scanf("%d",&n);
 	cin>>a>>d;
 	cin>>n;
 	double x=0,y=0;
	//aa=floor(a+0.05);
 	for(i=1;i<=n;i++){
					  
					  
					  double dd=d*i;
					  long long r=(long long)(dd/a);
					  int c;
					  long long l=(long long)(r/4);
					  //l=floor(l+0.00001);
					  c=r-l*4;
					  //cout<<l<<endl;
					  l=(long long)(dd/a);
					  
					  //l=floor(l+0.00001);
					  double h=dd-l*a;
					  //c=floor(c+0.00001);
					  if(c==1)x=a,y=h;
					  else if(c==2)y=a,x=a-h;
					  else if(c==3)x=0,y=a-h;
					  else y=0,x=h;
					  //x=aa-x;
					  printf("%1e %1e\n",x,y);
					  //cout<<x<<" "<<y<<endl;
					  //cout<<dd<<"        "<<r<<"   "<<c<<"  "<<l<<" "<<h<<endl;
    }							  
					  
	//system("pause");
	return 0;
}