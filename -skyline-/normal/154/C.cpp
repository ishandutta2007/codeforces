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
#include<unordered_map>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007ll
//:
using namespace std;
//
//
int n,m;
ll ans;
vector<int> v[1000005],v2[1000005];
unordered_map<ll,int> M,M2;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y),v[y].pb(x);
            v2[x].pb(y),v2[y].pb(x);
    }
    for(int i=1;i<=n;i++)v2[i].pb(i);
    for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end()),sort(v2[i].begin(),v2[i].end());
    for(int i=1;i<=n;i++){
            ll res=0;
            for(int j=0;j<v[i].size();j++)res=res*orz+v[i][j]*1ll;
            ans+=M[res];
            M[res]++;
            res=0;   
            for(int j=0;j<v2[i].size();j++)res=res*orz+v2[i][j]*1ll;
            ans+=M2[res];
            M2[res]++;
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}