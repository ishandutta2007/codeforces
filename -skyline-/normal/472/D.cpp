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
int n,a[2015][2015],s,f[2000008];
pair<int,int> q[2000008];
vector<pair<int,int> > v[2015];
inline int ope(int x){return f[x]==x?x:f[x]=ope(f[x]);};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n;i++){
            if(a[i][i]){
                        puts("NO");
                        return 0;
            }
            for(int j=1;j<i;j++){
                    if(a[i][j]!=a[j][i]||a[i][j]==0){
                                                     puts("NO");
                                                     return 0;
                    }
                    q[++s]=make_pair(a[i][j],(i<<11)+j);
                    f[s]=s;
            }
    }
    sort(q+1,q+s+1);
    int k=1;
    for(int i=1;i<n;i++){
            while(ope(q[k].second>>11)==ope(q[k].second&2047))k++;
            int x=q[k].second>>11,y=q[k].second&2047;
            f[f[x]]=f[y];
            v[x].push_back(make_pair(y,q[k].first));
            v[y].push_back(make_pair(x,q[k].first));
    }
    for(int i=1;i<=n;i++){
            int p[2015],ps=0,pe=1,b[2015];
            p[1]=i;
            memset(b,-1,sizeof(b));
            b[i]=0;
            while(ps<pe){
                         int x=p[++ps];
                         for(int j=0;j<v[x].size();j++){
                                 if(b[v[x][j].first]){
                                                      p[++pe]=v[x][j].first;
                                                      if(a[i][p[pe]]!=v[x][j].second+a[i][x]){
                                                                                              puts("NO");
                                                                                              return 0;
                                                      }               
                                                      b[p[pe]]=0;
                                 }
                         }
            }
    }
    puts("YES");                                                                    
	//system("pause");
	return 0;
}