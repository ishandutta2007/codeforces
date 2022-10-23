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
vector<int> v[100005];
int n,m,a[100005],res[1000005],ans;
bool b[100005];
void cty(int x){
     b[x]=1;
     a[x]^=1;
     res[++ans]=x;
     for(int i=0;i<v[x].size();i++){
             if(b[v[x][i]]) continue;
             cty(v[x][i]);
             res[++ans]=x;
             a[x]^=1;
             if(a[v[x][i]]){
                            res[++ans]=v[x][i];
                            res[++ans]=x;
                            a[v[x][i]]=0;
                            a[x]^=1;
             }
     }
}        
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
    }
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
            if(a[i]){
                     cty(i);
                     break;
            }
    }
    while(a[res[ans]])a[res[ans]]=0,ans--;
    bool ok=1;               
    for(int i=1;i<=n;i++)if(a[i])ok=0;
    if(!ok){
            printf("-1\n");
            return 0;
    }
    printf("%d\n",ans);
    if(ans){
            for(int i=1;i<ans;i++)printf("%d ",res[i]);
            printf("%d\n",res[ans]);
    }
	//system("pause");
	return 0;
}