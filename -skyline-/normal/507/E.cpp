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
int n,mm,k,l[100005],d[100005],g[100005],sum;
bool us[100005];
pair<int,int> ans;
vector<pair<int,int> >v[100005];
map<pair<int,int>,int> m;
queue<int> q;
void ope(){
     while(!q.empty()){
                       int x=q.front();
                       q.pop();
                       if(x==n) continue;
                       us[x]=0;
                       for(int i=0;i<v[x].size();i++){
                               int u=v[x][i].first;
                               if(d[u]>d[x]+1||(d[u]==d[x]+1&&g[u]<g[x]+v[x][i].second)){
                                                                                         d[u]=d[x]+1;
                                                                                         g[u]=g[x]+v[x][i].second;
                                                                                         l[u]=x;
                                                                                         if(!us[u])us[u]=1,q.push(u);
                               }
                       }
     }
                       
                               
                                                                                         
                                                                                         
                                
}                                                                               
                                                                                 
int main()
{
    scanf("%d%d",&n,&mm);
    for(int i=2;i<=n;i++)d[i]=2147483640;
    for(int i=1;i<=mm;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
            sum+=z;
    }
    q.push(1);
    ope();                 
    sum+=d[n];
    sum-=g[n]*2;
    int i=n;
    //for(int i=1;i<=n;i++)cout<<d[i]<<g[i]<<l[i]<<endl;
    while(i!=1){
                m[make_pair(i,l[i])]=m[make_pair(l[i],i)]=1;
                i=l[i];
    }
    printf("%d\n",sum);
    for(int i=1;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                    if(v[i][j].first<i) continue;
                    if(m[make_pair(i,v[i][j].first)]^v[i][j].second){
                                                                     if(v[i][j].second)printf("%d %d 0\n",i,v[i][j].first);
                                                                     else printf("%d %d 1\n",i,v[i][j].first);
                    }
            }
    }                                                    
    //system("pause");
    return 0;
}