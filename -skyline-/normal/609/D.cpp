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
ll n,m,k,s,f[3][200005],p[3][200005],W[3];
pair<ll,ll> w[3][200005];
bool ok(int x){
     ll res=0;
     int w1=1,w2=1;
     for(int i=1;i<=k;i++){
             ll q1=w[1][w1].first*p[1][x],q2=w[2][w2].first*p[2][x];
             if(q1<q2)w1++,res+=q1;
             else w2++,res+=q2;
     }
     return res<=s;
}
             
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&s);
    p[1][0]=p[2][0]=2147483640,p[1][n+1]=p[2][n+1]=0,f[1][n+1]=f[2][n+1]=n+1;
    for(int i=1;i<=n;i++){
            scanf("%I64d",p[1]+i);
            if(p[1][i]>=p[1][i-1])f[1][i]=f[1][i-1],p[1][i]=p[1][i-1];
            else f[1][i]=i;
    }
    for(int i=1;i<=n;i++){
            scanf("%I64d",p[2]+i);
            if(p[2][i]>=p[2][i-1])f[2][i]=f[2][i-1],p[2][i]=p[2][i-1];
            else f[2][i]=i;
    }
    for(int i=1;i<=m;i++){
            int q1;
            ll q2;
            scanf("%d%I64d",&q1,&q2);
            w[q1][++W[q1]]=make_pair(q2,i);
    }
    sort(w[1]+1,w[1]+W[1]+1);
    sort(w[2]+1,w[2]+W[2]+1);
    w[1][++W[1]]=w[2][++W[2]]=make_pair(21474836400000ll,0);
    ll l=1,r=n+1;
    while(r-l>1){
                 ll o=(l+r)/2;
                 if(ok(o))r=o;
                 else l=o;
    }
    while(!ok(l))l++;
    if(l>n)printf("-1\n");
    else{
         int w1=1,w2=1;
         printf("%I64d\n",l);
         for(int i=1;i<=k;i++){
                 if(w[1][w1].first*p[1][l]<w[2][w2].first*p[2][l])printf("%I64d %I64d\n",w[1][w1++].second,f[1][l]);
                 else printf("%I64d %I64d\n",w[2][w2++].second,f[2][l]);
         }
    }
  //  system("pause");
    return 0;
}