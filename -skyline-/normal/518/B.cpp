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
string s,t;
int a[200],b[200],ans,res;
int main()
{
    cin>>s;
    cin>>t;
    for(int i=0;i<s.size();i++)a[s[i]]++;
    for(int i=0;i<t.size();i++)b[t[i]]++;
    for(char i='A';i<='Z';i++){
             int x=min(a[i],b[i]),y=min(a[i+32],b[i+32]);
             ans+=(x+y);
             a[i]-=x;
             b[i]-=x;
             a[i+32]-=y;
             b[i+32]-=y;
             res+=(min(a[i],b[i+32])+min(a[i+32],b[i]));
    }
    cout<<ans<<' '<<res<<endl;         
    //system("pause");
    return 0;
}