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
int n,x[300],y[300],f[205][205],ans;
int ope(int k){
    queue<int> q;
    int a[300005],u=k,v;
    memset(a,-1,sizeof(a));  
    q.push(k);
    a[k]=0; 
    while(!q.empty()){
                      int o=q.front();
                      q.pop();         
                      if(a[o]>a[u])u=o;
                      for(int i=1;i<=n;i++){
                              if(f[o][i]&&a[i]==-1)a[i]=a[o]+1,q.push(i);
                      }
    }
    v=u;
    memset(a,-1,sizeof(a));  
    q.push(u);
    a[u]=0; 
    while(!q.empty()){
                      int o=q.front();
                      q.pop();         
                      if(a[o]>a[v])v=o;
                      for(int i=1;i<=n;i++){
                              if(f[o][i]&&a[i]==-1)a[i]=a[o]+1,q.push(i);
                      }
    }
    return a[v];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
            scanf("%d%d",x+i,y+i);
            f[x[i]][y[i]]=f[y[i]][x[i]]=1;
    }
    for(int i=1;i<n;i++){
            f[x[i]][y[i]]=f[y[i]][x[i]]=0;
            ans=max(ans,ope(x[i])*ope(y[i]));
            f[x[i]][y[i]]=f[y[i]][x[i]]=1;
    }
    printf("%d\n",ans);           
	//system("pause");
	return 0;
}