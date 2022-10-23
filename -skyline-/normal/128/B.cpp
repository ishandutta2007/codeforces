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
string s,ans,ss;
       
struct pp  
{  
       string s;
       int t;   
       bool operator <(pp a) const  
       {  
               return a.s<s;
       }  
};
int k;
priority_queue<pp>q;
int main()
{
    cin>>s>>k;
    ss="";
    for(int i=s.size()-1;i>=0;i--){
            pp x;
            x.s=s[i];
            x.t=i;
            q.push(x);
    }
    k++;
    while(--k&&!q.empty()){
               pp p=q.top();
               q.pop();
               ans=p.s;
               p.t++;
               if(p.t!=s.size()){
                                 p.s+=s[p.t];
                                 q.push(p);
               }
    }
    if(k)puts("No such line.");
    else cout<<ans<<endl;                            
    //system("pause");
    return 0;
}