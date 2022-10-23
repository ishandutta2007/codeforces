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
map<string,int> m;
string name[20],e,w;
int n,q;
bool f[20][20];
set<string> res,ans;
inline void ope(int k){
       if(k>n){
               if(res.size()>ans.size())ans=res;
               return;
       }
       set<string>::iterator it;
       for(it=res.begin();it!=res.end();it++) if(f[m[*it]][k]) break;
       if(it==res.end()){
                         res.insert(name[k]);
                         ope(k+1);
                         res.erase(name[k]);
       }
       ope(k+1);
}
               
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
            cin>>name[i];
            m[name[i]]=i;
    }
    while(q--){
               cin>>w>>e;
               f[m[w]][m[e]]=1;
               f[m[e]][m[w]]=1;
    }
    ope(1);
    cout<<ans.size()<<endl;
    set<string>::iterator it;
    for(it=ans.begin();it!=ans.end();it++)cout<<*it<<endl;              
    //system("pause");
    return 0;
}