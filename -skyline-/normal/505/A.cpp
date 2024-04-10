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
string s,ans;
bool ope(){
     for(int i=0;i<ans.size()/2;i++){
             if(ans[i]!=ans[ans.size()-1-i]) return 0;
     }
     return 1;
}
             
int main()
{
    cin>>s;
    for(int i=0;i<=s.size();i++){
            for(char c='a';c<='z';c++){
                     ans="";
                     for(int j=0;j<i;j++)ans+=s[j];
                     ans+=c;
                     for(int j=i;j<s.size();j++)ans+=s[j];
                     if(ope()){
                               cout<<ans<<endl;
                              // system("pause");
                               return 0;
                     }
            }
    }
    cout<<"NA"<<endl;
    return 0;
}