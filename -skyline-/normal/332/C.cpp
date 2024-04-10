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
using namespace std;
int n,p,k,a[100005],b[100005],q[100005],_;
ll f[100005],g[100005];
bool cmp(int i,int j){return mp(-b[i],a[i])<mp(-b[j],a[j]);}
int main(){
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=n;++i)scanf("%d%d",a+i,b+i),q[i]=i;
    sort(q+1,q+n+1,cmp);
    set<pair<int,int> >s;
    for(int i=1;i<=k;++i)s.insert(mp(a[q[i]],i)),f[k]+=a[q[i]];
    for(int i=k+1;i<=n;++i){
        f[i]=f[i-1]+a[q[i]];
        s.insert(mp(a[q[i]],i));
        f[i]-=s.begin()->first;
        s.erase(s.begin());
    }
    s.clear();
    for(int i=n;i>n-p+k;--i)s.insert(mp(b[q[i]],i)),g[n-p+k+1]+=b[q[i]];
    for(int i=n-p+k;i;--i){
        g[i]=g[i+1]+b[q[i]];
        s.insert(mp(b[q[i]],i));
        g[i]-=s.begin()->first;
        s.erase(s.begin());
    }
    s.clear();
    _=k;
    for(int i=k+1;i<=n-p+k;++i)if(mp(f[i],g[i+1])>mp(f[_],g[_+1]))_=i;
    for(int i=1;i<=k;++i)s.insert(mp(a[q[i]],i));
    for(int i=k+1;i<=_;++i){
        s.insert(mp(a[q[i]],i));
        s.erase(s.begin());
    }
    while(!s.empty()){
        printf("%d ",q[s.begin()->second]);
        s.erase(s.begin());
    }
    for(int i=n;i>n-p+k;--i)s.insert(mp(b[q[i]],i));
    for(int i=n-p+k;i>_;--i){
        s.insert(mp(b[q[i]],i));
        s.erase(s.begin());
    }
    while(!s.empty()){
        printf("%d ",q[s.begin()->second]);
        s.erase(s.begin());
    }
   // system("pause");
    return 0;
}