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
int i,j,k=0,l=1,a[200000],n,x[200000],y[200000];

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++){
                     j=i;
                     while(j<=n&&a[j]<a[j+1])j++;
                     k++;
                     x[k]=i;
                     y[k]=j;
                     l=max(l,j-i+1+(j!=n||i!=1));
                     i=j;
                     
    }
    for(i=1;i<=k-2;i++){
                        if(x[i+1]==y[i+1]&&(a[x[i+2]]-a[y[i]])>=2)l=max(l,y[i+2]-x[i]+1);
    }
    for(i=1;i<=k-1;i++){
                        if((a[x[i+1]+1]-a[y[i]])>=2)l=max(l,y[i+1]-x[i]+1);
    }
    for(i=1;i<=k-1;i++){
                        if((a[x[i+1]]-a[y[i]-1])>=2)l=max(l,y[i+1]-x[i]+1);
    }
                        
                        
    cout<<l<<endl;
                     
                          
   // system("pause");
    return 0;
}