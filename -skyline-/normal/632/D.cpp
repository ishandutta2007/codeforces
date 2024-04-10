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
//
int n,m,a[1000005],ans,k=1,b[1000005],q,f[1000005];
vector<int> v[1000005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x<=m)a[x]++,v[x].pb(i);
    }
    for(int i=1;i<=m;i++){          
            for(int j=i;j<=m;j+=i)f[j]+=a[i];
    }
    for(int i=1;i<=m;i++){
            if(f[i]>ans)ans=f[i],k=i;
    }  
    printf("%d %d\n",k,ans);
    for(int i=1;i<=m;i++){
            if(k%i) continue;
            for(int j=0;j<v[i].size();j++)b[++q]=v[i][j];
    }
    sort(b+1,b+q+1);
    for(int i=1;i<=q;i++)printf("%d ",b[i]);
//	system("pause");
	return 0;
}