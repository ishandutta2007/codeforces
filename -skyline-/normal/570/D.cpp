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
int n,m,f[500005],d[500005],o[500005],in[500005],out[500005],l,q[500005][30];
char c[500005];
vector<int> v[500005];
pair<pair<int,int>,int> p[500005];
void ope(int k){
     o[k]=d[k];
     in[k]=++l;
     for(int i=0;i<v[k].size();i++){
             d[v[k][i]]=d[k]+1;
             ope(v[k][i]);
             o[k]=max(o[k],o[v[k][i]]);
     }
     out[k]=l;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)scanf("%d",f+i),v[f[i]].push_back(i);
    scanf("%s",c+1);
    d[1]=1;
    ope(1);
    for(int i=1;i<=n;i++)p[i]=make_pair(make_pair(d[i],in[i]),i);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++)q[i][j]+=q[i-1][j];
            q[i][c[p[i].second]-'a']^=1;
    }
    while(m--){
               int v,h;
               scanf("%d%d",&v,&h);
               if(d[v]>h||o[v]<h){
                                  printf("Yes\n");
                                  continue;
               }
               int l=lower_bound(p+1,p+n+1,make_pair(make_pair(h,in[v]),0))-p;
               int r=lower_bound(p+1,p+n+1,make_pair(make_pair(h,out[v]+1),0))-p-1;        
               int ans=0;
               for(int i=0;i<26;i++)ans+=(q[r][i]-q[l-1][i])&1;
               printf(ans<=1?"Yes\n":"No\n");
    }
                       
   // system("pause");
	return 0;
}