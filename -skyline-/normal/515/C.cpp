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
int n,a[20],b[10];
string s;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;i++)a[i]=s[i-1]-48;
    for(int i=1;i<=n;i++){
            int k=a[i];
            for(int j=2;j<k;j++)a[i]*=j;
                          while(a[i]%2==0&&a[i]>1){
                                           a[i]/=2;
                                           b[2]++;
                          }
                          while(a[i]%3==0&&a[i]>1){
                                           a[i]/=3;
                                           b[3]++;
                          }
                          while(a[i]%5==0&&a[i]>1){
                                           a[i]/=5;
                                           b[5]++;
                          }
                          while(a[i]%7==0&&a[i]>1){
                                           a[i]/=7;
                                           b[7]++;
                          }
    }
    b[5]-=b[7];
    b[3]-=b[7]*2+b[5];
    b[2]-=b[7]*4+b[5]*3+b[3];       
    for(int i=1;i<=b[7];i++)cout<<7; 
    for(int i=1;i<=b[5];i++)cout<<5; 
    for(int i=1;i<=b[3];i++)cout<<3;
    for(int i=1;i<=b[2];i++)cout<<2;
    cout<<endl;                                                                    
   // system("pause");
    return 0;
}