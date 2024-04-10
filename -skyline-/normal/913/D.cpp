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
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int n,T,a[200005],t[200005],p[200005];
bool ok(int x){
    int k=0;
    for(int i=1;i<=n;i++)if(a[i]>=x)p[++k]=t[i];
    if(x>k) return 0;
    sort(p+1,p+k+1);
    int ans=0;
    for(int i=1;i<=x;i++)ans+=p[i];
    return ans<=T;
}
int main(){
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)scanf("%d%d",a+i,t+i);
    int l=0,r=n;
    while(r-l>1){
        int m=(l+r)>>1;
        if(ok(m))l=m;
        else r=m;
    }
    while(ok(l+1))l++;
    while(!ok(l))l--;
    printf("%d\n%d\n",l,l);
    vector<pair<int,int> >v;
    for(int i=1;i<=n;i++)if(a[i]>=l)v.pb(mp(t[i],i));
    sort(v.begin(),v.end());
    for(int i=0;i<l;i++)printf("%d ",v[i].second);
	//system("pause");
	return 0;
}