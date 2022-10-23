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
#define ll   long long
//:
using namespace std;
map<pair<int,int>,int> m;
int n,x[100005],y[100005];
ll ans;
set<pair<int,int> > alive;
set<int> s;
set<int>::iterator it;  
void ins(pair<int,int> p){
     if(!alive.count(p)) return;
     int k=m[p];
     if(alive.count(make_pair(x[k]-1,y[k]+1)))if(!alive.count(make_pair(x[k]-2,y[k]))&&!alive.count(make_pair(x[k]-1,y[k]))) return;
     if(alive.count(make_pair(x[k],y[k]+1)))if(!alive.count(make_pair(x[k]-1,y[k]))&&!alive.count(make_pair(x[k]+1,y[k]))) return;
     if(alive.count(make_pair(x[k]+1,y[k]+1)))if(!alive.count(make_pair(x[k]+1,y[k]))&&!alive.count(make_pair(x[k]+2,y[k]))) return;
     s.insert(k);
}    
bool del(int k){
     s.erase(k);
     if(alive.count(make_pair(x[k]-1,y[k]+1)))if(!alive.count(make_pair(x[k]-2,y[k]))&&!alive.count(make_pair(x[k]-1,y[k]))) return 0;
     if(alive.count(make_pair(x[k],y[k]+1)))if(!alive.count(make_pair(x[k]-1,y[k]))&&!alive.count(make_pair(x[k]+1,y[k]))) return 0;
     if(alive.count(make_pair(x[k]+1,y[k]+1)))if(!alive.count(make_pair(x[k]+1,y[k]))&&!alive.count(make_pair(x[k]+2,y[k]))) return 0;
     alive.erase(make_pair(x[k],y[k]));
     if(y[k]){
              ins(make_pair(x[k]-1,y[k]-1));
              ins(make_pair(x[k],y[k]-1));
              ins(make_pair(x[k]+1,y[k]-1));
     }
     return 1;
}                               
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            scanf("%d%d",x+i,y+i);
            m[make_pair(x[i],y[i])]=i;
            alive.insert(make_pair(x[i],y[i]));
    }
    for(int i=0;i<n;i++)ins(make_pair(x[i],y[i]));
    for(int i=1;!s.empty();i^=1){
            int t;        
            while(1){
                     if(i)it=s.end(),it--;
                     else it=s.begin();
                     t=*it;
                     if(del(*it)) break;
            }
            ans=(ans*n+t)%1000000009;
    }
    printf("%I64d\n",ans);
   // system("pause");
    return 0;
}