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
int n;
vector<int> v[200005];
int f[200005],g[200005];
bool b[200005];
int a[200005];
char c[2]={'b','r'};
void cty(int x,int y){
	if(b[x]) return;
	b[x]=1,a[x]=y;
	for(int i=0;i<v[x].size();i++)cty(v[x][i],y^1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(f[x])v[i].pb(f[x]),v[f[x]].pb(i),f[x]=0;
		else f[x]=i;
		if(g[y])v[i].pb(g[y]),v[g[y]].pb(i),g[y]=0;
		else g[y]=i;
	}
	for(int i=1;i<=n;i++)cty(i,0);
	for(int i=1;i<=n;i++)printf("%c",c[a[i]]);
	printf("\n");
	return 0;
}