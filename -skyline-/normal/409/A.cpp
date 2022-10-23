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
char x[30],y[30];
int main(){
	cin>>x>>y;
	int i;
	int a=0,b=0;
	for(i=0;x[i]!='\0';i+=2){
							   if(x[i]=='8'&&y[i]=='[')a++;
							   if(x[i]=='['&&y[i]=='8')b++;
							   if(x[i]=='['&&y[i]=='(')a++;
							   if(x[i]=='('&&y[i]=='[')b++;
							   if(x[i]=='('&&y[i]=='8')a++;
							   if(x[i]=='8'&&y[i]=='(')b++;
							   //cout<<a<<"  "<<b<<endl;
    }
	if(a==b)cout<<"TIE"<<endl;
	if(a>b)cout<<"TEAM 1 WINS"<<endl;
	if(a<b)cout<<"TEAM 2 WINS"<<endl;					   
	//system("pause");
	return 0;
}