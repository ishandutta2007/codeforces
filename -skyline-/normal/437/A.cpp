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
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    pair<int,char> l[10];
    l[1]=make_pair(a.size()-2,'A');
    l[2]=make_pair(b.size()-2,'B');
    l[3]=make_pair(c.size()-2,'C');
    l[4]=make_pair(d.size()-2,'D');
    sort(l+1,l+5);
    bool x=(l[1].first*2<=l[2].first);
    bool y=(l[3].first*2<=l[4].first);
    if(x==1&&y==0)cout<<l[1].second<<endl;
    else if(x==0&&y==1)cout<<l[4].second<<endl;
    else cout<<'C'<<endl;
  //  system("pause");
    return 0;
}