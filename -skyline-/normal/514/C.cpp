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
int n,m;
long long moder=1000000007,ter=257,f[700000];
set<long long> s;
inline long long hash(string x){
       long long l=0;
       for(int i=0;i<x.size();i++)l=(l*ter+x[i])%moder;
       return l;
}
       
int main()
{
    string t;
    cin>>n>>m;
    f[0]=1;
    f[1]=ter;
    for(int i=2;i<688888;i++)f[i]=f[i-1]*ter%moder;
    for(int i=1;i<=n;i++){
            cin>>t;
            s.insert(hash(t));
            
    }
    for(int j=1;j<=m;j++){
            cin>>t;
            long long mo=hash(t),l=t.size(),fff=0;
            for(int i=0;i<l;i++){
                    for(char c='a';c<='c';c++){
                             if(t[i]==c) continue;
                             if(s.count(((f[l-i-1]*(c-t[i])+mo)%moder+moder)%moder)){
                                                                                     fff=1;
                                                                                     i=l+1;
                                                                                     break;
                             }
                    }
            }
                    
            if(fff){
                           puts("YES");
            }
            else puts("NO");
    }
                                   
                             
   // system("pause");
    return 0;
}