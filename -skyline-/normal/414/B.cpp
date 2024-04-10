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
int b=1000000007,s;
int a[2014][2014];
int l,k;
   
     
int main()
{
    cin>>k>>l;
    int i,j;
    for(i=1;i<=l;i++){
                      for(j=1;j<=k;j++){
                                        if(i==1)a[i][j]=1;
                                        else{
                                             for(int h=j;h<=k;h+=j)a[i][j]+=a[i-1][h],a[i][j]=a[i][j]%b;
                                        }
                      }
    }
    for(i=1;i<=k;i++)s+=a[l][i],s=s%b;
    cout<<s<<endl;                  
    //system("pause");
    return 0;
}