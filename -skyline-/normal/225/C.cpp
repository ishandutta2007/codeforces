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
int r,c,x,y;
char cc[1200][1200];
int b[1200],w[1200],fb[1200],fw[1200];
int main()
{
    cin>>r>>c>>x>>y;
    int i,j,k,l;
    for(i=1;i<=r;i++){
                      for(j=1;j<=c;j++){
                                        cin>>cc[i][j];
                                        if(cc[i][j]=='.')w[j]++;
                                        else b[j]++;
                      }
    }
    for(i=1;i<=c;i++){
                      fb[i]=100000000;
                      fw[i]=100000000;
                      w[i]=w[i]+w[i-1];
                      b[i]=b[i]+b[i-1];
    }
    //for(i=1;i<=x;i++)fb[i]=w[i],fw[i]=b[i];
    for(i=0;i<=c;i++) {
                      for(j=x;j<=y;j++){
                                        fb[i+j]=min(fb[i+j],fw[i]+w[i+j]-w[i]);
                                        fw[i+j]=min(fw[i+j],fb[i]+b[i+j]-b[i]); 
                      }
    }
    cout<<min(fb[c],fw[c])<<endl;                                 
                                        
    //system("pause");
    return 0;
}