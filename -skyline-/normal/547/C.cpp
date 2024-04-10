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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
//:
using namespace std;
int b[500005],f[500005],n,q,g[500005],r[200005];
ll ans;
vector<int> v[500005];
int main(){
    int O=0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",r+i);
    g[1]=1;
    for(int i=1;i<=500000;i++){
        v[i].pb(i);
        for(int j=i*2;j<=500000;j+=i)v[j].pb(i),g[j]-=g[i];
    }
    while(q--){
        int x,y;
        scanf("%d",&y);
        x=r[y];
        if(b[y]){
            b[y]=0;
            for(int i=0;i<v[x].size();i++)ans-=(--f[v[x][i]])*g[v[x][i]];
        }
        else{
            b[y]=1;
            for(int i=0;i<v[x].size();i++)ans+=(f[v[x][i]]++)*g[v[x][i]];
        }
        printf("%I64d\n",ans);
    }
//	system("pause");
	return 0;
}