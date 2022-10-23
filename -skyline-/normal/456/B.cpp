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
string s;
char c[300000];
int main()
{
    cin>>c;
    s=c;
    int l=s.size();
    if(l==1){
             int ans=c[0]-48;
             ans=ans%4;
             if(ans==0){
                        cout<<4<<endl;
             }
             else{
                  cout<<0<<endl;
             }
             return 0;
    }
             
    int a=c[l-2]-48,b=c[l-1]-48;
    int ans=a*10+b;
    ans=ans%4;
    if(ans==0){
               cout<<4<<endl;
    }
    else{
         cout<<0<<endl;
    }
                    
	//system("pause");
	return 0;
}