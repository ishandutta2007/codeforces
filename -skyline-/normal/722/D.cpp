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
#include<unordered_map>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//
unordered_map<int,bool> m;
int n,a[50005];
bool ok(int x){
    m.clear();
    for(int i=1;i<=n;i++){
        int k=a[i];
        while(k>x)k>>=1;
        while(k&&m.count(k))k>>=1;
        if(k)m[k]=1;
        else return 0;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i*2<=n;i++)swap(a[i],a[n+1-i]);
    int l=n,r=a[1];
    while(r-l>1){
        int m=(l+r)/2;
        if(ok(m))r=m;
        else l=m;
    }
    if(!ok(l))l=r;
    m.clear();
    for(int i=1;i<=n;i++){
        int k=a[i];
        while(k>l)k>>=1;
        while(k&&m.count(k))k>>=1;
        m[k]=1;
        printf("%d ",k);
    }
	return 0;
}