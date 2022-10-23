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
int n,m,u[100002],ok,ans,f[100002];
vector<int> v1[100002],v2[100002],res;
inline void ope(int x){
                if(u[x]) return;
                u[x]=1;
                res.push_back(x);
                for(int i=0;i<v2[x].size();i++)ope(v2[x][i]);
}

inline void dfs(int x){
       if(!ok||f[x]==2) return;
       if(f[x]==1){
                   ok=0;
                   ans++;
                   return;
       }
       f[x]=1;
       for(int i=0;i<v1[x].size();i++)dfs(v1[x][i]);
       f[x]=2;
}
                                                          
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            v1[x].push_back(y);
            v2[x].push_back(y);
            v2[y].push_back(x);
    }
    ans=0;
    for(int i=1;i<=n;i++){
            if(u[i]) continue;
            res.clear();   
            ope(i);
            ans+=res.size()-1;
            ok=1;          
            for(int j=0;j<res.size()&&ok;j++){
                    if(!f[res[j]])dfs(res[j]);
            }
    }
    cout<<ans<<endl;
   // system("pause");
    return 0;
}