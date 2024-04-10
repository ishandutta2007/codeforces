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
int n,m,s,ans[100005],a[100005],so[100005],u[300005];
vector<int> v[300005];
inline bool cmp(int x,int y){
       return a[x]<a[y];
}

inline bool ope(int x){
       u[x]=1;
       for(int i=0;i<v[x].size();i++){
               if(u[v[x][i]]==1) return 1;
               if(!u[v[x][i]]&&ope(v[x][i])) return 1;
       }
       u[x]=2;
       if(x<=n)ans[s--]=x;
       return 0;
}
                     
int main()
{
    scanf("%d%d",&m,&n);
    s=n;
    while(m--){
                   for(int i=1;i<=n;i++)scanf("%d",a+i);
                   for(int i=1;i<=n;i++)so[i]=i;
                   sort(so+1,so+n+1,cmp);
                   int st=1;
                   while(a[so[st]]==-1)st++;
                   /*for(int i=st;i<n;i++){
                           if(a[so[i]]==a[so[i+1]]) continue;
                           int j=i,k=i+1;
                           while(a[so[j]]==a[so[j-1]])j--;
                           while(a[so[k]]==a[so[k+1]])k++;
                           if(j==i){
                                    for(int l=i+1;l<=k;l++)v[so[j]].push_back(so[l]);
                           }
                           else if(k==i+1){
                                for(int l=j;l<=i;l++)v[so[l]].push_back(so[k]);
                           }
                           else{
                                s++;
                                for(int l=j;l<=i;l++)v[so[l]].push_back(s);
                                for(int l=i+1;l<=k;l++)v[s].push_back(so[l]);
                           }
                   }*/
                   s++;
                   int k=st;
                   for(int i=st;i<=n;i=k){
                           s++;
                           while(a[so[k]]==a[so[i]]){
                                                     v[s-1].push_back(so[k]);
                                                     v[so[k]].push_back(s);
                                                     k++;
                           }
                   }                                
    }
    int k=s;
    s=n;
    for(int i=1;i<=k;i++){
            if(!u[i]&&ope(i)){
                              puts("-1");
                              return 0;
            }
    }
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);                                                            
    //system("pause");
    return 0;
}