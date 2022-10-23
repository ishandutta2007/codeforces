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
double fpower(double a,int b){
       double ans=1;
       while(b!=0){
                   if(b%2==1)ans*=a;
                   b/=2;
                   a=a*a;
       }
       return ans;
}
                   
int main() 
{
    double i,j,k,l,m;
    int n;
    double ans=0.00;
    cin>>m>>n;
    for(i=1;i<=m;i++){
                      double d=i*(fpower(i*1.0/m,n)-fpower((i-1.0)/m,n))*1.0;
                      ans+=d;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
	//system("pause");
	return 0;
}