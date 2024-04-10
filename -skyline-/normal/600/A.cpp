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
#define ll   long long
//:
using namespace std;
string s,c="";
vector<string> num,oth;
int n;
bool ok(string s){
     if(s=="0") return 1;
     if(s=="") return 0;
     if(s[0]=='0') return 0;
     bool f=0;
     int l=s.size();
     for(int i=0;i<l;i++)if(s[i]>'9'||s[i]<'0') f=1;
     return f^1;
}
int main()
{
    cin>>s;
    s+=',';
    n=s.size();
    for(int i=0;i<n;i++){
            if(s[i]==','||s[i]==';'){
                                     if(ok(c))num.push_back(c);
                                     else oth.push_back(c);
                                     c="";
            }
            else c+=s[i];
    }
    if(num.size()){
                   cout<<'"'<<num[0];
                   for(int i=1;i<num.size();i++)cout<<','<<num[i];
                   cout<<'"'<<endl;
    }
    else cout<<"-\n";
    if(oth.size()){
                   cout<<'"'<<oth[0];
                   for(int i=1;i<oth.size();i++)cout<<','<<oth[i];
                   cout<<'"'<<endl;
    }
    else cout<<"-\n";      
	//system("pause");
	return 0;
}