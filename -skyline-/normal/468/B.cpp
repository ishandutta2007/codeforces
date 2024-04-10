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
set<int> s;
map<int,int> m;
int n,a,b,t,ans[100005];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            s.insert(x);
            m[x]=i;
    }
    if(a>b)swap(a,b),t=1;
    while(!s.empty()){
                      int x=*s.begin();                 
                      s.erase(x);
                      if(x*2==b){
                                 ans[m[x]]=1;
                      }
                      else if(s.count(b-x)){
                                       ans[m[x]]=1;
                                       ans[m[b-x]]=1;
                                       s.erase(b-x);
                      }
                      else if(x*2==a) continue;
                      else if(s.count(a-x))s.erase(a-x);
                      else{
                           puts("NO");
                           return 0;
                      }           
    }
    puts("YES");
    for(int i=1;i<n;i++)printf("%d ",ans[i]^t);
    printf("%d\n",ans[n]^t);                       
   // system("pause");
    return 0;
}