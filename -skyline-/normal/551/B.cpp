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
string a,b,c;
int x[150],y[150],z[150],m,mb,mc;
int main()
{
    cin>>a;
    cin>>b;
    cin>>c;
    for(int i=0;i<a.size();i++)x[a[i]]++;
    for(int i=0;i<b.size();i++)y[b[i]]++;
    for(int i=0;i<c.size();i++)z[c[i]]++;
    for(int i=0;i<=a.size();i++){
            int k=1000000;
            for(int j='a';j<='z';j++){
                    if(y[j]*i>x[j]){
                                    i=a.size();
                                    break;
                    }
                    if(z[j])k=min(k,(x[j]-y[j]*i)/z[j]);
            }
            if(i+k>m&&i<a.size())m=i+k,mb=i,mc=k;
    }
    for(int i=1;i<=mb;i++)cout<<b;
    for(int i=1;i<=mc;i++)cout<<c;
    for(char i='a';i<='z';i++){
            for(int j=1;j<=x[i]-y[i]*mb-z[i]*mc;j++)cout<<i;
    }
    cout<<endl;                                        
	//system("pause");
	return 0;
}