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
int n,m,s[200005];
vector<int> v[200005];
int x[200005],y[200005],z[200005],k;
bool u[200005],q[200005];
void cty(int o,int f){
     u[o]=1;
     int p=0,F=0;
     for(int i=0;i<v[o].size();i++){ 
             if(f+o==s[v[o][i]]){
                                 F=v[o][i];
                                 continue;
             }        
             if(q[v[o][i]]) continue;
             int O=s[v[o][i]]-o;
             if(!u[O])cty(O,o); 
             if(q[v[o][i]]) continue;
             if(q[p])p=0;
             if(!p)p=v[o][i];
             else x[++k]=s[p]-o,y[k]=o,z[k]=O,q[p]=q[v[o][i]]=1,p=0;
     }
     if(q[p])p=0;
     if(p&&f&&!q[F]&&F!=p)q[F]=q[p]=1,x[++k]=s[p]-o,y[k]=o,z[k]=f;
}
                   
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].pb(i),v[b].pb(i);
            s[i]=a+b;
    }
    for(int i=1;i<=n;i++){
            if(u[i]) continue;
            cty(i,0);
    }
    printf("%d\n",k);
    for(int i=1;i<=k;i++)printf("%d %d %d\n",x[i],y[i],z[i]);
	//system("pause");
	return 0;
}