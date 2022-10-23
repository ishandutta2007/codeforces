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
#define orz  998244353ll
using namespace std;
int t,n,m,u[300005],cnt[5];
bool ok;
ll b[300005];
vector<int> v[300005];
void dfs(int x,int y){
    if(u[x]+y==3) ok=0;
    if(!ok) return;
    u[x]=y,++cnt[y];
    for(int i=0;i<v[x].size();++i)if(u[v[x][i]]!=3-y)dfs(v[x][i],3-y);
}
int main(){
    b[0]=1;
    for(int i=1;i<=300000;++i)b[i]=b[i-1]*2ll%orz;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)v[i].clear(),u[i]=0;
        for(int i=1;i<=m;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y),v[y].pb(x);
        }
        ll ans=1;
        for(int i=1;i<=n;++i){
            if(u[i]) continue;
            ok=1,cnt[1]=cnt[2]=0;
            dfs(i,1);
            if(!ok){
                ans=0;
                break;
            }
            ans*=(b[cnt[1]]+b[cnt[2]])%orz;
            ans%=orz;
        }
        ans=(ans%orz+orz)%orz;
        printf("%I64d\n",ans);
    }
//	system("pause");
	return 0;
}