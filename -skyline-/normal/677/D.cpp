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
#define X    first
#define Y    second
#define ins  insert
//:
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int n,m,p,a[305][305],z;
vector<pair<int,pair<int,int> > > v[90005]; 
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf("%d",a[i]+j),v[a[i][j]].pb(mp(orz,mp(i,j)));
    }
    v[0].pb(mp(0,mp(1,1)));
    for(int i=0;i<p;i++){
            sort(v[i].begin(),v[i].end());
            if(v[i].size()>1000) v[i].resize(1000);
            for(int l=0;l<v[i].size();l++){
                    for(int j=0;j<v[i+1].size();j++)v[i+1][j].X=min(v[i+1][j].X,v[i][l].X+abs(v[i+1][j].Y.Y-v[i][l].Y.Y)+abs(v[i+1][j].Y.X-v[i][l].Y.X));
            }
    }
    printf("%d\n",v[p][0].X);
//	system("pause");
	return 0;
}