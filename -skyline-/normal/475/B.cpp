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
int p[23][23],n,m,s,k[502];
bool u[502];
vector<int> v1[502],v2[502],v;
inline void ope(int x){
       if(u[x]) return;
       u[x]=1;
       for(int i=0;i<v1[x].size();i++)ope(v1[x][i]);
       v.push_back(x);
}

inline void dfs(int x){
       k[x]=s;
       for(int i=0;i<v2[x].size();i++)if(!k[v2[x][i]])dfs(v2[x][i]);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)p[i][j]=++s;
    }
    for(int i=1;i<=n;i++){
            char c;
            cin>>c;
            if(c=='>'){
                       for(int j=1;j<m;j++){
                               v1[p[i][j]].push_back(p[i][j+1]);
                               v2[p[i][j+1]].push_back(p[i][j]);
                       }
            }
            else{
                 for(int j=1;j<m;j++){
                         v2[p[i][j]].push_back(p[i][j+1]);
                         v1[p[i][j+1]].push_back(p[i][j]);
                 }
            }
    }
    for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='v'){
                       for(int i=1;i<n;i++){
                               v1[p[i][j]].push_back(p[i+1][j]);
                               v2[p[i+1][j]].push_back(p[i][j]);
                       }
            }
            else{
                 for(int i=1;i<n;i++){
                         v2[p[i][j]].push_back(p[i+1][j]);
                         v1[p[i+1][j]].push_back(p[i][j]);
                 }
            }
    }
    s=0;
    for(int i=1;i<=n*m;i++)if(!u[i])ope(i);
    for(int i=v.size()-1;i>=0;i--)if(!k[v[i]])s++,dfs(v[i]);
    puts(s==1?"YES":"NO");
    //system("pause");
    return 0;
}