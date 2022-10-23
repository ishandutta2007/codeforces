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
int n,t;
double p,f[2015][2015],ans,res;
int main()
{
    cin>>n;
    cin>>p;
    cin>>t;
    f[0][0]=1.0;
    for(int i=1;i<=t;i++){
            int l=min(n,i);
            f[i][0]=1.0-f[i-1][l]*p;
            for(int j=1;j<=l;j++){
                    f[i][j]+=f[i-1][j-1]*p+f[i-1][j]*(1-p);
                    f[i][0]-=f[i][j];
            }
            f[i][l]+=f[i-1][l]*p;
    }
    int l=min(n,t);
    //res=f[t][0];
    for(int i=1;i<=l;i++){
            double d=i;
            d*=f[t][i];
            ans+=d;
            //res+=f[t][i];
            //printf("%.5f ",f[t][i]);
    }
    //ans/=res;
    printf("%.10f\n",ans);                        
   // system("pause");
    return 0;
}