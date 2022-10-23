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
int n,a[3005],f[3005][3005],c[3005],ans[3005];
pair<int,int> q[3005];
vector<int> res;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),q[i]=mp(a[i],i);
    for(int i=1;i<=3;i++)res.pb(0);       
    for(int i=1;i<=3;i++)res.pb(n+1-i);
    sort(q+1,q+n+1);
    for(int i=1;i<=n;i++)c[i]=q[i].first-q[i-1].first;
    for(int i=1;i<=n;i++){
            f[i][i]=i;        
            for(int j=i+1;j<=n;j++){
                    if(c[j]>c[f[i][j-1]])f[i][j]=j;
                    else f[i][j]=f[i][j-1];
            }
    }
    for(int i=1;i<n;i++){
            for(int j=1;j<n-i;j++){
                    if(j>i*2||i>j*2) continue;
                    int l=1,r=n-i-j;
                    l=max(l,(i+1)>>1);
                    l=max(l,(j+1)>>1);
                    r=min(r,i<<1);
                    r=min(r,j<<1);
                    if(l>r) continue;
                    l=f[n-i-j-r+1][n-i-j-l+1];
                    vector<int> v;
                    v.pb(c[n-i+1]);
                    v.pb(c[n-i-j+1]);
                    v.pb(c[l]);
                    v.pb(n-i+1);
                    v.pb(n-i-j+1);
                    v.pb(l);
                    if(v>res)res=v;
            }
    }
    for(int i=1;i<=n;i++){
            if(i>=res[3])ans[q[i].second]=1;
            else if(i>=res[4])ans[q[i].second]=2;
            else if(i>=res[5])ans[q[i].second]=3;
            else ans[q[i].second]=-1;
    }
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
//	system("pause");
	return 0;
}