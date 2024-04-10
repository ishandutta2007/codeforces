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
map<int,bool> m;
int n,k;
int main()
{
 	cin>>n>>k;
 	int i,j;
 	if(k<(n/2)||(n==1&&k!=0)){
                cout<<-1<<endl;
                return 0;
    }
    int f=k-(n/2)+1;
    if(n==1){
             cout<<1<<endl;
             return 0;
    }
             
    cout<<f<<' '<<f*2<<' ';
    m[f]=1;
    m[f*2]=1;
    n-=2;
    int ll=1;
    while(n>1){
               i=ll;
               while(m[i]==1||m[i+1]==1)i++;
               m[i]=1;
               m[i+1]=1;
               cout<<i<<' '<<i+1<<' ';
               n-=2;
               ll=i+2;
    }
    if(n==1){
             i=1;
             while(m[i]==1)i++;
             cout<<i<<endl;
    }
                                    
	//system("pause");
	return 0;
}