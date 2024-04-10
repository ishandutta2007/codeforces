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
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int n,m,o=1,f[100005],ans=-1,l,r,x[100005],y[100005],q[100005];
vector<int> v[100005];
void add(int k){
     f[x[k]]=1;
     v[x[k]].pb(y[k]);
}
int cty(int x){
    if(q[x]) return q[x];
    for(int i=0;i<v[x].size();i++)q[x]=max(q[x],cty(v[x][i]));
    q[x]++;
    return q[x];
}
bool ok(){
     int o=0,res=0;
     for(int i=1;i<=n;i++){
             if(!f[i]){
                       if(o) return 0;
                       o=i;
             }
     }
     memset(q,0,sizeof(q));
     q[o]=1;
     for(int i=1;i<=n;i++)res=max(res,cty(i));
     return res==n;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
            scanf("%d%d",x+i,y+i);
            if(i==m||i%300==0){
                               l=r+1;
                               r=i;
                               for(int j=l;j<=r;j++)add(j);
                               if(ok()){
                                        for(int j=1;j<=n;j++)v[j].clear();
                                        memset(f,0,sizeof(f));
                                        for(int j=1;j<l;j++)add(j);
                                        for(int j=l;j<=r;j++){
                                                add(j);
                                                if(ok())ans=j,j=r+1;
                                        }
                                        if(ans!=-1) break;
                               }
            }
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}