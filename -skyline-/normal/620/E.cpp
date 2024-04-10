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
//:
using namespace std;
int a[400005],b[400005],s,n,m,q[400005];
vector<int> v[400005];
ll c[1050000],d[1050000];
void ope(int k){
     a[k]=++s;
     for(int i=0;i<v[k].size();i++)if(!a[v[k][i]])ope(v[k][i]);
     b[k]=s;
}
void cty(ll o,int l,int r,int x,int y,int k){ 
     if(l>r||l>y||r<x) return;
     if(l<=x&&r>=y)d[k]=c[k]=o;
     else{
          int z=k<<1,m=(x+y)>>1;
          if(d[k])d[z]=d[z^1]=c[z]=c[z^1]=d[k],d[k]=0;
          cty(o,l,r,x,m,z);
          cty(o,l,r,m+1,y,z^1);
          c[k]=c[z]|c[z^1];                                 
     }                                                         
}
ll ac(int l,int r,int x,int y,int k){
          if(l>r||l>y||r<x) return 0;
          if(l<=x&&r>=y) return c[k];
          else{
               int z=k<<1,m=(x+y)>>1;  
               if(d[k])d[z]=d[z^1]=c[z]=c[z^1]=d[k],d[k]=0;
               return ac(l,r,x,m,z)|ac(l,r,m+1,y,z^1);
          }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",q+i);
    for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
    }
    ope(1);
    for(int i=1;i<=n;i++)c[a[i]+524287]=1ll<<q[i];
    for(int i=524287;i;i--)c[i]=c[i<<1]|c[(i<<1)^1];
    while(m--){
               int t,x;
               scanf("%d%d",&t,&x);
               if(t==1){
                        int y;
                        scanf("%d",&y);
                        ll o=1ll<<y;
                        cty(o,a[x],b[x],1,524288,1);
               }
               else{
                    ll o=ac(a[x],b[x],1,524288,1);
                    int ans=0;
                    for(int i=1;i<=60;i++)ans+=((o>>i)&1ll);
                    printf("%d\n",ans);
               }
    }
//	system("pause");
	return 0;
}