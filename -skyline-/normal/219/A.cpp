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
//:
using namespace std;
int k,l,a[200];
string s;
int main()
{
    cin>>k>>s;
    l=s.size();
    for(int i=0;i<l;i++)a[s[i]]++;
    if(l%k){
               puts("-1");
               return 0;
    }
    s="";
    for(char i='a';i<='z';i++){
             if(a[i]%k){
                        puts("-1");
                        return 0;
             }
             for(int j=1;j<=a[i]/k;j++)s+=i;
    }
    for(int i=1;i<=k;i++)cout<<s;
    cout<<endl;         
    //system("pause");
    return 0;
}