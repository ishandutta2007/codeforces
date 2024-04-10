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
int n,a[100005],b[100005],l[100005],r[100005],q[100005];
set<int> s[100005];
vector<int> ansx,ansy;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-3;++i)scanf("%d%d",a+i,b+i),s[a[i]].insert(b[i]),s[b[i]].insert(a[i]);
    for(int i=1;i<=n-3;++i)scanf("%d%d",a+i,b+i);
    for(int i=1;i<=n;++i)l[i]=i-1,r[i]=i+1;
    l[1]=n,r[n]=1;
    for(int i=1;i<=n-3;++i){
        int k=0;
        for(int j=1;j<=n-3;++j){
            if(l[l[a[j]]]==b[j])swap(a[j],b[j]);
            if(r[r[a[j]]]==b[j]&&(!k||s[r[a[j]]].size()<s[r[a[k]]].size()))k=j;
        }
        int o=r[a[k]],Q=0;
        if(!s[o].size()){
            r[a[k]]=b[k],l[b[k]]=a[k];
            continue;
        }
        int O=l[o];
        while(O!=o){
            if(s[o].count(O)){
                s[O].erase(o);
                if(O!=a[k]&&O!=b[k])q[Q++]=O;
            }
            O=l[O];
        }
        s[o].clear(),q[Q]=b[k];
        for(int i=1;i<=Q;++i)ansx.pb(o),ansy.pb(q[i-1]),s[a[k]].insert(q[i]),s[q[i]].insert(a[k]);
        r[a[k]]=b[k],l[b[k]]=a[k];
        
    }
    printf("%d\n",ansx.size());
    for(int i=0;i<ansx.size();++i)printf("%d %d\n",ansx[i],ansy[i]);
	//system("pause");
	return 0;
}