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
int n,a[20000],b[50000],c[50000],d[50000];
int main()
{
    int i,j,k,l;
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1)b[0]++,b[b[0]]=i;
            if(a[i]==2)c[0]++,c[c[0]]=i;
            if(a[i]==3)d[0]++,d[d[0]]=i;
    }
    int w=min(b[0],min(c[0],d[0]));
    cout<<w<<endl;
    for(i=1;i<=w;i++)cout<<b[i]<<' '<<c[i]<<' '<<d[i]<<endl;       
    //system("pause");
    return 0;
}