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
int n,mm,s,it;
int a[200005],r[200005],so[200005],ne[200005];
bool u[200005];
string ss,na[200005];
vector<int> v[200005];   
queue<int> q;
map<string,int> m;
inline string sb(string v){
       for(int i=0;i<v.size();i++)if(v[i]<'a')v[i]+=32;
       return v;
}
            
inline void ope(string &x){
       x=sb(x);
       if(m[x]) return;
       m[x]=++s;
       for(int i=0;i<x.size();i++)r[s]+=(x[i]=='r');
       na[s]=x;
       so[s]=s;
       return;
}

inline bool cmp(int x,int y){
       if(r[x]!=r[y]) return r[x]<r[y];
       return na[x].size()<na[y].size();
}
inline bool same(int x,int y){
       return r[x]==r[y]&&na[x].size()==na[y].size();
}
inline void dfs(int x,int y){
       if(u[x]) return;
       u[x]=1;
       ne[x]=y;
       for(int i=0;i<v[x].size();i++)dfs(v[x][i],y);
}
             
                                
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>ss;
            ope(ss);
            a[i]=m[ss];
    }
    m[""]=200002;
    r[200002]=2147483640;       
    cin>>mm;
    for(int i=1;i<=mm;i++){
            string p,q;
            cin>>p>>q;
            ope(p);
            ope(q);
            v[m[q]].push_back(m[p]);
    }
    sort(so+1,so+s+1,cmp);
    for(int i=1;i<=s;i++)dfs(so[i],so[i]);
    long long rr=0,ll=0;
    for(int i=1;i<=n;i++)rr+=r[ne[a[i]]],ll+=na[ne[a[i]]].size();
    //for(int i=1;i<=s;i++)cout<<so[i]<<' '<<na[so[i]]<<' '<<ne[so[i]]<<' '<<r[so[i]]<<endl;
    cout<<rr<<' '<<ll<<endl;                          
    //system("pause");
    return 0;
}