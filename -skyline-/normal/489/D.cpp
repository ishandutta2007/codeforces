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
ll n,m,ans;
bool a[3005][3005];
vector<ll> v[3005];
int main()
{
    scanf("%I64d%I64d",&n,&m);
    for(int i=1;i<=m;i++){
            ll x,y;
            scanf("%I64d%I64d",&x,&y);
            a[x][y]=1;
            v[x].push_back(y);
    }
    for(ll i=1;i<n;i++){
           for(ll j=i+1;j<=n;j++){
                  ll s=0;
                  for(int k=0;k<v[i].size();k++)s+=a[v[i][k]][j];
                  ans+=s*(s-1);
                  s=0;
                  for(int k=0;k<v[j].size();k++)s+=a[v[j][k]][i];
                  ans+=s*(s-1);
           }
    }
    printf("%I64d\n",ans/2);                
	//system("pause");
	return 0;
}