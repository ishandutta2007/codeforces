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
int n,m,a[200],b[200];
int main()
{
    cin>>n>>m;
    int k,x;
    cin>>k;
    for(int i=1;i<=k;i++)cin>>x,a[x]=1;
    cin>>k;
    for(int i=1;i<=k;i++)cin>>x,b[x]=1;
    int g=__gcd(n,m);
    for(int i=0;i<g;i++){
            int f=0;
            for(int j=i;j<n;j+=g)f+=a[j];
            for(int j=i;j<m;j+=g)f+=b[j];
            if(!f){
                   puts("No");
                   return 0;
            }
    }
    puts("Yes");        
                   
	//system("pause");
	return 0;
}