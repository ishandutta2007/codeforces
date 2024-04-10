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
int a[100005];
int main()
{
    int i,j,k,l,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    a[n+1]=2147483646;
    for(k=1;k<=n;k++)if(a[k]>a[k+1]) break;
    for(l=n;l>0;l--)if(a[l]<a[l-1]) break;
    if(k>l&&n!=2){
            cout<<"yes"<<endl;
            cout<<"1 1"<<endl;
            return 0;
    }
    if(n==2){
             if(a[1]<a[2]){
                           cout<<"yes"<<endl;
                           cout<<"1 1"<<endl;
             }
             else{
                  cout<<"yes"<<endl;
                  cout<<"1 2"<<endl;
             }
             return 0;
    }
             
                  
                           
                           
    for(i=k;i<l;i++){
                      if(a[i]<a[i+1]){
                                      cout<<"no"<<endl;
                                      return 0;
                      }
    }
    if(a[k]<a[l+1]&&a[l]>a[k-1]){
                                 cout<<"yes"<<endl;
                                 cout<<k<<' '<<l<<endl;
    }
    else{
         cout<<"no"<<endl;
    }
                                      
   // system("pause");
    return 0;
}