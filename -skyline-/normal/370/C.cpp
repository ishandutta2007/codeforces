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
int i,j,k,l,n,m,b[10005];
pair<int,int > a[105];
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++){
                      cin>>k;
                      a[k].first++;
                      b[i]=k;
    }
    for(i=1;i<=m;i++)a[i].second=i,l=max(l,a[i].first);
    cout<<min((n-l)*2,n)<<endl;
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++){
                      cout<<b[i]<<' '<<b[(i+n/2-1)%n+1]<<endl;
    }
                                         
                       
    //system("pause");
    return 0;
}