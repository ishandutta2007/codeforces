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
#define orz  998244353
using namespace std;
int n,k,l,a[100005],f[100005][105],nx[100005][105],s[100005][105];
void add(int &x,int y){
    x+=y;
    if(x>=orz)x-=orz;
}
int main(){
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<=k;++i){
        nx[n+1][i]=n;
        for(int j=n;j;--j){
            if(a[j]==-1||a[j]==i)nx[j][i]=nx[j+1][i];
            else nx[j][i]=j-1;
        }
    }
    for(int i=0;i<n;++i){
        int o=(i==0);
        for(int j=1;j<=k;++j)add(o,f[i][j]);
        for(int j=1;j<=k;++j){
            if(a[i+1]!=-1&&a[i+1]!=j) continue;
            int p=o;
            add(p,orz-f[i][j]);
            add(s[i+1][j],p),add(s[min(i+l,nx[i+1][j]+1)][j],orz-p);
        }
        for(int j=1;j<=k;++j)add(s[i+1][j],s[i][j]),add(f[i+1][j],s[i+1][j]);
    }
    int ans=0;
    for(int i=1;i<=k;++i)add(ans,f[n][i]);
    printf("%d\n",ans);
//	system("pause");
	return 0;
}