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
int n,s=1;
pair<int,int> p[2030];
int main()
{
    int i,j=0,k,l;
    cin>>n;
    for(i=1;i<=n;i++){
                      cin>>k;
                      p[i]=make_pair(k,i);
    }
    sort(p+1,p+n+1);
    for(i=2;i<=n;i++){
                      if(p[i].first==p[i-1].first)j++;
    }
    if(j<2){
            puts("NO");
            return 0;
    }
    puts("YES");
    for(i=1;i<n;i++)cout<<p[i].second<<' ';
    cout<<p[n].second<<endl;
    for(i=1;i<n;i++){
                     if(p[i].first==p[i+1].first&&p[i].second<p[i+1].second){
                                                                             swap(p[i],p[i+1]);
                                                                             break;
                     }
    }
    for(i=1;i<n;i++)cout<<p[i].second<<' ';
    cout<<p[n].second<<endl;
    for(i=1;i<n;i++){
                     if(p[i].first==p[i+1].first&&p[i].second<p[i+1].second){
                                                                             swap(p[i],p[i+1]);
                                                                             break;
                     }
    }
    for(i=1;i<n;i++)cout<<p[i].second<<' ';
    cout<<p[n].second<<endl;               
                                                                          
    //system("pause");
    return 0;
}