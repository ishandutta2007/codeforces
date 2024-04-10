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
#define fi   first
#define se   second
using namespace std;
int T,n,m,a[200005],f[200005][20],b[200005];
pair<int,int> p[200005];
int get(int l,int r){
    int d=b[r-l];
    return max(f[l][d],f[r-(1<<d)+1][d]);
}
int main(){
    for(int i=1;i<=200000;++i){
        b[i]=b[i-1];
        if(i==(2<<b[i]))++b[i];
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",a+i),f[i][0]=a[i];
        for(int k=0;k<=17;++k){
            for(int i=n-(1<<k);i>=0;--i)f[i][k+1]=max(f[i][k],f[i+(1<<k)][k]);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;++i)scanf("%d%d",&p[i].se,&p[i].fi);
        sort(p+1,p+m+1);
        for(int i=m-1;i;--i)p[i].se=max(p[i].se,p[i+1].se);
        int l=1,ans=0;
        while(l<=n){
            if(a[l]>p[1].se){
                ans=-1;
                break;
            }
            int o=0;
            for(int i=18;i>=0;--i){
                int O=o+(1<<i);
                if(l+O-1>n||O>p[m].fi) continue;
                int oo=0;
                for(int j=18;j>=0;--j){
                    int OO=oo+(1<<j);
                    if(OO<=m&&p[OO].fi<O)oo=OO;
                }
                if(p[oo+1].se>=get(l,l+O-1))o=O;
            }
            ++ans;
            l+=o;
        }
        printf("%d\n",ans);
    }
   // system("pause");
    return 0;
}