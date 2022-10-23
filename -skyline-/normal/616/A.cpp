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
string s1,s2,sa="",sb="";
int n,m,l1,l2;
int main()
{
    cin>>s1;
    cin>>s2;
    l1=s1.size();
    l2=s2.size();
    while(s1[n]=='0'&&n<l1)n++;
    while(s2[m]=='0'&&m<l2)m++;
    for(int i=n;i<l1;i++)sa+=s1[i];
    for(int i=m;i<l2;i++)sb+=s2[i];
    if(sa.size()!=sb.size()){
                             if(sa.size()>sb.size())printf(">\n");
                             else printf("<\n");
    }
    else if(sa==sb)printf("=\n");
    else if(sa<sb)printf("<\n");
    else printf(">\n");
 //   system("pause");
    return 0;
}