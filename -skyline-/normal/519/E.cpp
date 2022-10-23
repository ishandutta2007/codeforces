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
int n,p[20][100006],d[100006],f[100006];
vector<int> v[100006];
int ope(int k,int l){
    d[k]=d[l]+1;
    p[0][k]=l;
    f[k]=1;
    for(int i=1;i<=19;i++)p[i][k]=p[i-1][p[i-1][k]];
    for(int i=0;i<v[k].size();i++)if(v[k][i]!=l)f[k]+=ope(v[k][i],k);
    return f[k];
}

int lca(int x,int y){
    for(int i=0;i<=19;i++)if((d[y]-d[x])>>i&1)y=p[i][y];
    for(int i=19;i>=0;i--){
            if(p[i][x]!=p[i][y])x=p[i][x],y=p[i][y];
    }
    if(x!=y)x=p[0][x];
    return x;
}
            
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
    }
    ope(1,1);
    int q;
    scanf("%d",&q);
    while(q--){
               int x,y;
               scanf("%d%d",&x,&y);
               if(d[x]>d[y]) swap(x,y);
               int ans=0,r=lca(x,y),l=d[x]+d[y]-d[r]-d[r],t=l>>1;
               t--;
               if(!(l&1)){
                    if(d[x]==d[y]){
                                   for(int i=0;i<=19;i++){
                                           if(t&(1<<i))y=p[i][y];
                                   }
                                   for(int i=0;i<=19;i++){
                                           if(t&(1<<i))x=p[i][x];
                                   }
                                   ans=n-f[x]-f[y];
                    }           
                    else{
                         for(int i=0;i<=19;i++){
                                 if(t&(1<<i))y=p[i][y];
                         }
                         ans=f[p[0][y]]-f[y];
                    }
               }
               if(ans<0) ans=-ans;         
               printf("%d\n",ans);
    }
	//system("pause");
	return 0;
}