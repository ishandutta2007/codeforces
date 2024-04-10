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
int main()
{
    char a[12]={'A','H','I','M','O','T','U','V','W','X','Y'};
    int i,j,r=0;
    string s;
    cin>>s;
    int l=s.size();
    if(l==1&&(s[0]=='A'||s[0]=='H'||s[0]=='I'||s[0]=='M'||s[0]=='O'||s[0]=='T'||s[0]=='U'||s[0]=='V'||s[0]=='W'||s[0]=='X'||s[0]=='Y')){cout<<"YES"<<endl; return 0;};
    int h;
    for(i=1;i<=(l+3)/2;i++){
                           if(s[i-1]!=s[l-i])r=1;
                           h=0;
                           for(j=0;j<=10;j++)if(s[i-1]==a[j])h++;
                           if(r==1||h==0) break;
    }
    if(r==1||h==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;                       
    //system("pause");
    return 0;
}