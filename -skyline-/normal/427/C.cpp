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
long long n,m,c[100002],s,k[100002],moder=1000000007,f[100002],res=1,sumer;
bool u[100002];
vector<long long> v1[100002],v2[100002],v,ans[100002];
inline void ope(long long x){
       if(u[x]) return;
       u[x]=1;
       for(int i=0;i<v1[x].size();i++)ope(v1[x][i]);
       v.push_back(x);
}

inline void dfs(long long x){
       k[x]=s;
       for(int i=0;i<v2[x].size();i++)if(!k[v2[x][i]])dfs(v2[x][i]);
       ans[s].push_back(x);
}
       
int main()
{
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",f+i);
    scanf("%I64d",&m);
    for(int i=1;i<=m;i++){
            long long x,y;
            scanf("%I64d%I64d",&x,&y);
            v1[x].push_back(y);
            v2[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(!u[i])ope(i);
    for(int i=v.size()-1;i>=0;i--)if(!k[v[i]])s++,dfs(v[i]);
    for(int i=1;i<=s;i++){
            long long num=2147483640,sum=0;
            for(int j=0;j<ans[i].size();j++){
                    if(f[ans[i][j]]<num) num=f[ans[i][j]],sum=1;
                    else if(f[ans[i][j]]==num) sum++;
            }
            res=(res*sum)%moder;
            sumer+=num;
    }
    printf("%I64d %I64d\n",sumer,res);                                   
    //system("pause");
    return 0;
}