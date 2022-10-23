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
int f[300],a[300],b[300];
int main()
{
    int n,m,i,j,l,k;
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>f[i];
    int ma=f[1];
    for(i=1;i<=n;i++){
                      for(j=i;j<=n;j++){
                                        int x=0,y=0,s=0;
                                        int kk=k;
                                        for(l=1;l<=n;l++){
                                                          
                                                          if(l<i||l>j)y++,b[y]=f[l];
                                                          else x++,a[x]=f[l];
                                        }
                                        k=min(k,y);
                                        sort(b+1,b+y+1);
                                        for(l=1;l<=k;l++)a[x+l]=b[y+1-l];
                                        sort(a+1,a+x+k+1);
                                        for(l=k+1;l<=x+k;l++)s+=a[l];
                                        ma=max(ma,s);k=kk;
                      }
    }
    cout<<ma<<endl;                  
                                        
	//system("pause");
	return 0;
}