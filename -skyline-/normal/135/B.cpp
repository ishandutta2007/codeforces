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
int x[10],y[10],q[10];
inline int pf(int n){
       return (n*n);
}
inline int lon(int a,int b){
       int A=q[a],B=q[b];
       return pf(x[A]-x[B])+pf(y[A]-y[B]);
}
       
int main()
{
    int i,j,k,l;
    for(i=1;i<=8;i++){
                      cin>>x[i]>>y[i];
                      q[i]=i;
    }
    do{
                      bool yes;
                      yes=((lon(1,2)==lon(2,3))&&(lon(1,2)==lon(3,4))&&(lon(1,2)==lon(1,4))&&(lon(1,3)==lon(2,4))&&(lon(5,6)==lon(7,8))&&(lon(5,7)==lon(6,8))&&(lon(5,8)==lon(6,7)));
                      if(yes==0) continue;
                      cout<<"YES"<<endl;
                      cout<<q[1]<<' '<<q[2]<<' '<<q[3]<<' '<<q[4]<<endl;
                      cout<<q[5]<<' '<<q[6]<<' '<<q[7]<<' '<<q[8]<<endl;
                     // system("pause");
                      return 0;
    }while(next_permutation(q+1,q+9));
    cout<<"NO"<<endl;                  
   // system("pause");
    return 0;
}