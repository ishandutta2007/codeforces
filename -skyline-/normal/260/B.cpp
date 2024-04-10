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
int d[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string s;
bool ifis(int it){
	 if(s[it+2]!='-'||s[it+5]!='-'){
	 							   return 0;
     }
     if(s[it]>'9'||s[it]<'0'||s[it+1]>'9'||s[it+1]<'0'||s[it+3]>'9'||s[it+3]<'0'||s[it+4]>'9'||s[it+4]<'0'||s[it+6]>'9'||s[it+6]<'0'||s[it+7]>'9'||s[it+7]<'0'||s[it+8]>'9'||s[it+8]<'0'||s[it+9]>'9'||s[it+9]<'0'){
	 																																																				return 0;
	 }
	 if(s[it+6]!='2'||s[it+7]!='0'||s[it+8]!='1'||s[it+9]<'3'||s[it+9]>'5'){
	 																  return 0;
     }
	 int m=(s[it+3]-'0')*10+s[it+4]-'0';
	 if(m>12||m<1){
	 			   return 0;
     }
	 int da=(s[it]-'0')*10+s[it+1]-'0';
	 if(da>d[m]||da==0){
	 					return 0;
     }
	 return 1;
}
map<string,int> tj;	 								   																  																																																				
int main()
{
 	cin>>s;
 	string n;
 	n="          ";
 	tj[n]=-1;
 	for(int i=0;i<=s.size()-10;i++){
			if(ifis(i)==1){
						   string t=s.substr(i,10);
						   tj[t]++;
						   n=(tj[t]>tj[n]?t:n);
            }
    }					   
	cout<<n<<endl;
	//system("pause");
	return 0;
}