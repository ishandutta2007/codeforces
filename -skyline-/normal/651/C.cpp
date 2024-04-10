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
map<int,int> ma,mb;
map<pair<int,int>,int>m;
vector<pair<int,int> >v;
int x[200005],y[200005],n,X,Y;
ll ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(!ma[a])ma[a]=++X;
            if(!mb[b])mb[b]=++Y;
            int q=ma[a],w=mb[b];
            x[q]++;
            y[w]++;
            if(!m[mp(q,w)])v.pb(mp(q,w));
            m[mp(q,w)]++;
    }
    for(int i=1;i<=X;i++){
            ll o=x[i];
            o=o*(o-1)/2;
            ans+=o;
    }
    for(int i=1;i<=Y;i++){
            ll o=y[i];
            o=o*(o-1)/2;
            ans+=o;
    }
    for(int i=0;i<v.size();i++){
            ll o=m[v[i]];
            o=o*(o-1)/2;
            ans-=o;
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}