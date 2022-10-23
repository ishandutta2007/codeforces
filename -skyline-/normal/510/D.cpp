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
long long n,c[70005],l[70005],nn;
map<long long,bool> m;
set<pair<long long,long long> > s;
int main()
{
    cin>>nn;
    n=nn;
    for(int i=1;i<=n;i++)cin>>l[i];
    for(int i=1;i<=n;i++){
            cin>>c[i];
            s.insert(make_pair(c[i],l[i]));
    }
    while(!s.empty()){
                      long long p=s.begin()->first,q=s.begin()->second;
                      s.erase(s.begin());
                      if(m[q]) continue;
                      m[q]=1;
                      if(q==1){
                               cout<<p<<endl;
                               //system("pause");
                               return 0;
                      }
                      for(int i=nn;i<=n;i++)s.insert(make_pair(p+c[i],__gcd(l[i],q)));
                      n++;
                      c[n]=p,l[n]=q;
    }
    cout<<-1<<endl;                                        
    return 0;
}