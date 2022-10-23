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
#define orz  1000000007ll
//:
using namespace std;
//
//
int n,x[100005],y[100005],R,C,s;
map<int,int> r,c;
bool b,u[200005];
vector<int> v[200005];
ll ans=1;
void cty(int x,int p){
     s++;
     u[x]=1;
     for(int i=0;i<v[x].size();i++){
             if(v[x][i]==p) continue;
             if(u[v[x][i]])b=1;
             else cty(v[x][i],x);
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%d%d",x+i,y+i);
            if(!r[x[i]])r[x[i]]=++R;
            if(!c[y[i]])c[y[i]]=++C;
            x[i]=r[x[i]];
            y[i]=c[y[i]];
    }
    for(int i=1;i<=n;i++){
            v[x[i]].pb(y[i]+R);
            v[y[i]+R].pb(x[i]);
    }
    for(int i=1;i<=R+C;i++){
            if(u[i]) continue;
            b=0;
            s=0;
            cty(i,0);
            ll o=1;
            for(int j=1;j<=s;j++)o*=2ll,o%=orz;
            if(!b)o=o+orz-1ll;
            o%=orz;
            ans*=o;
            ans%=orz;
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}