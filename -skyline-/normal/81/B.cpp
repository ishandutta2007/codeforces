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
string s;
int l,k;
int main()
{
    getline(cin,s);
    l=s.size();
    for(int i=0;i+1<l;i++){
            if(s[i]!=' '){
                cout<<s[i];
                if(s[i]==','&&s[i+1]!=' ')cout<<' ';
                if(s[i]>='0'&&s[i]<='9'&&s[i+1]=='.')cout<<' ';
                if(s[i]=='.')k++;
                else k=0;
                if(k%3==0&&s[i+1]=='.'&&k)cout<<' ';
            }
            else{
                 if(s[i+1]==' ') continue;
                 int o=i;
                 while(s[o]==' '&&o)o--;
                 if(s[o]==' ') continue;
                if(s[o]==','&&s[i+1]!=' ')cout<<' ';
                if(s[o]>='0'&&s[o]<='9'&&s[i+1]=='.')cout<<' ';
                if(k%3==0&&s[i+1]=='.'&&k)cout<<' ';
                if(s[o]>='0'&&s[o]<='9'&&s[i+1]>='0'&&s[i+1]<='9')cout<<' ';
            }
    }
    if(s[l-1]!=' ')cout<<s[l-1];
    cout<<endl;
	//system("pause");
	return 0;
}