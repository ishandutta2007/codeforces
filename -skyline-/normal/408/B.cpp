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
int a[28],b[28];
string x,y;
int main()
{
    cin>>x;
    cin>>y;
    int i;
    for(i=0;i<x.size();i++)a[x[i]-96]++;
    for(i=0;i<y.size();i++)b[y[i]-96]++;
    int s=0;
    for(i=1;i<=26;i++){
                       if(b[i]==0){
                                   continue;
                       }
                       if(a[i]>b[i]){
                                     s+=b[i];
                                     continue;
                       }
                       if(a[i]==0){
                                   cout<<-1<<endl;
                                   return 0;
                       }
                       for(int j=a[i];j>0;j--){
                               if(b[i]%j==0){
                                                s+=a[i];
                                                break;
                               }
                       }
    }
                       
                               
                                                
                                                     
                       
    cout<<s<<endl;
    //system("pause");
    return 0;
}