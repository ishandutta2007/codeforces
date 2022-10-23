//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
//:
using namespace std;
//
//
int n,m,k,s,t,l=2500,X,Y;
int u[30],a[2505],c,p[5],dis[2505];
string ans="-1";
vector<int> v[2505];
int q[2505],qs,ps;
pair<pair<int,int>,int> P[2505];
string r[2505];
bool b[2505];
bool g[2505];
void cty(){
     q[1]=s;
     r[s]="";
     qs=1;
     memset(g,0,sizeof(g));
     b[1]=1;
     g[s]=1;
     while(qs){
               c=0;
               ps=0;
               for(int i=1;i<=qs;i++){
                       if(b[i])c++;
                       for(int j=0;j<v[q[i]].size();j++){
                               int k=v[q[i]][j];
                               if(g[k]||!u[a[k]]) continue;
                               g[k]=1;
                               P[++ps]=mp(mp(c,a[k]),k);
                               r[k]=r[q[i]]+(char)(96+a[k]);
                       }
               }
               sort(P+1,P+ps+1);
               b[1]=1;
               for(int i=2;i<=ps;i++)b[i]=(P[i].first!=P[i-1].first);
               qs=ps;
               for(int i=1;i<=ps;i++)q[i]=P[i].second;
     }
     if(!g[t]) return;
     r[t].erase(r[t].size()-1);
     if(r[t].size()<l||(r[t].size()==l&&r[t]<ans))ans=r[t],l=ans.size();
}                         
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    c++;
                    char x;
                    scanf(" %c",&x);
                    if(x=='S')s=c;
                    else if(x=='T')t=c,X=i,Y=j;
                    else a[c]=x-'a'+1;  
                    if(j<m)v[c].pb(c+1);
                    if(i>1)v[c].pb(c-m);
                    if(i<n)v[c].pb(c+m);
                    if(j>1)v[c].pb(c-1);
            }
    }
    for(int i=1;i<=k;i++)p[i]=i;
    while(!p[0]){
                 memset(u,0,sizeof(u));
                 u[0]=1;
                 for(int i=1;i<=k;i++)u[p[i]]=1;
                 cty();
                 int o=k;
                 while(p[o]==26+o-k)o--;
                 p[o]++;
                 for(int i=o+1;i<=k;i++)p[i]=p[i-1]+1;
    }
    cout<<ans<<endl;
  //	system("pause");
	return 0;
}