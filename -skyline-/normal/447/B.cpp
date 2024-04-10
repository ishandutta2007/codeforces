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
int main()
{
    int i,j,k=0,l=0,n,m,a[3000]={0},b[700]={0};
    char c[10000];
    string s;
    cin>>c>>m;
    s=c;
    for(i=0;i<s.size();i++)a[i]=c[i]-'a'+1;
    for(i=1;i<=26;i++)cin>>b[i],l=max(l,b[i]);
    for(i=0;i<s.size();i++)k+=(i+1)*b[a[i]];
    for(i=s.size()+1;i<=s.size()+m;i++)k+=i*l;
    cout<<k<<endl;
   // system("pause");
    return 0;
}