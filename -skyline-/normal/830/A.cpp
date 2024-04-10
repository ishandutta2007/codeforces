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
int n,k,p;
int a[1005],b[2005],B[2005];
int f[1005][2005];
int ans;
pair<int,int> q[1005];
bool u[2005];
bool ok(int x){
     for(int i=1;i<=n;i++){
             int l=k+1,r=0;
             for(int j=1;j<=k;j++)if(f[i][j]+B[j]<=x)l=min(l,j),r=j;
             if(l>k) return 0;
             q[i]=mp(r,l);
     }
     sort(q+1,q+n+1);
     memset(u,0,sizeof(u));
     for(int i=1;i<=n;i++){
             bool ok=0;
             for(int j=q[i].second;j<=q[i].first;j++){
                     if(u[j]==0)u[j]=1,ok=1,j=k;
             }
             if(!ok) return 0;
     }
     return 1;
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=k;i++)scanf("%d",b+i); 
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++)f[i][j]=abs(a[i]-b[j]);
    }
    for(int i=1;i<=k;i++)B[i]=abs(b[i]-p);
    int l=0,r=orz+orz;
    while(r-l>1){
                 int m=l+((r-l)>>1);
                 if(ok(m))ans=m,r=m;
                 else l=m;
    }
    while(ok(ans-1))ans--;
    printf("%d\n",ans);
//	system("pause");
	return 0;
}