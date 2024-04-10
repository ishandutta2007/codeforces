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
long long d1[102],d2[102],s1[102],s2[102],n,m,sum;
vector<long long> v[102],v1[102],v2[102];
queue<long long> q;
inline long long ope1(long long x){
       if(s1[x]) return s1[x];
       for(int i=0;i<v1[x].size();i++)s1[x]+=ope1(v1[x][i]);
       return s1[x];
}

inline long long ope2(long long x){
       if(s2[x]) return s2[x];
       for(int i=0;i<v2[x].size();i++)s2[x]+=ope2(v2[x][i]);
       return s2[x];
}       
int main()
{
    scanf("%I64d%I64d",&n,&m);
    for(int i=1;i<=m;i++){
            long long x,y;
            scanf("%I64d%I64d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
    }
    q.push(1);
    while(!q.empty()){
                      long long x=q.front();
                      q.pop();
                      for(int i=0;i<v[x].size();i++){
                              if(v[x][i]==1) continue;
                              if(!d1[v[x][i]]){
                                         q.push(v[x][i]);
                                         v1[v[x][i]].push_back(x);
                                         d1[v[x][i]]=d1[x]+1;
                              }
                              else if(d1[x]+1==d1[v[x][i]])v1[v[x][i]].push_back(x);
                      }
    }
    s1[1]=1;
    for(int i=2;i<=n;i++)s1[i]=ope1(i);                  
    q.push(n);
    while(!q.empty()){
                      long long x=q.front();
                      q.pop();
                      for(int i=0;i<v[x].size();i++){
                              if(v[x][i]==n) continue;
                              if(!d2[v[x][i]]){
                                         q.push(v[x][i]);
                                         v2[v[x][i]].push_back(x);
                                         d2[v[x][i]]=d2[x]+1;
                              }
                              else if(d2[x]+1==d2[v[x][i]])v2[v[x][i]].push_back(x);
                      }
    }
    s2[n]=1;
    for(int i=1;i<n;i++)s2[i]=ope2(i);                          
    sum=s1[n];
    //for(int i=1;i<=n;i++) cout<<d1[i]<<' '<<s1[i]<<' '<<d2[i]<<' '<<s2[i]<<endl;
    for(int i=2;i<n;i++)if(d1[n]==d1[i]+d2[i])sum=max(sum,s1[i]*s2[i]*2);
    double num=sum*1.00,times=s1[n]*1.00;
    double res=num*1.0/times*1.0;
    printf("%.10f\n",res);
    //system("pause");
    return 0;
}