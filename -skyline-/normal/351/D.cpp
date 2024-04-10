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
#define fi   first
#define se   second
using namespace std;
int n,a[100005],la[100005],nx[100005],nw[100005],len[100005],fst[100005];
vector<pair<int,int> >add[100005],del[100005],ask[100005];
int q,l[100005],r[100005],ans[100005],t[100005],cnt[100005];
pair<pair<int,int>,int> p[100005];
void ad(int x){while(x<=n)++t[x],x+=(x&-x);}
void de(int x){while(x<=n)--t[x],x+=(x&-x);}
int get(int x){int ans=0;while(x)ans+=t[x],x-=(x&-x);return ans;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<=n;++i){
        la[i]=nw[a[i]];
        nw[a[i]]=i;
        if(la[i]){
            len[i]=i-la[i];
            if(len[la[i]]==len[i]||!len[la[i]])fst[i]=fst[la[i]];
            else fst[i]=la[i];
        }
        else fst[i]=i;
    }
    for(int i=1;i<=100000;++i)nw[i]=n+1;
    for(int i=n;i;i--){
        nx[i]=nw[a[i]];
        nw[a[i]]=i;
        add[la[fst[i]]+1].pb(mp(i,nx[i]-1));
        del[i].pb(mp(i,nx[i]-1));
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i)scanf("%d%d",l+i,r+i),ask[l[i]].pb(mp(r[i],i)),p[i]=mp(mp(l[i]/300,r[i]),i);
    for(int i=1;i<=n;++i){
        for(int j=0;j<add[i].size();++j)ad(add[i][j].fi),de(add[i][j].se+1);
        for(int j=0;j<ask[i].size();++j)if(!get(ask[i][j].fi))ans[ask[i][j].se]=1;
        for(int j=0;j<del[i].size();++j)de(del[i][j].fi),ad(del[i][j].se+1);
    }
    sort(p+1,p+q+1);
    int L=1,R=0,res=0;
    for(int i=1;i<=q;++i){
        int k=p[i].se;
        while(R<r[k])res+=((++cnt[a[++R]])==1);
        while(L>l[k])res+=((++cnt[a[--L]])==1);
        while(L<l[k])res-=((--cnt[a[L++]])==0);
        while(R>r[k])res-=((--cnt[a[R--]])==0);
        ans[k]+=res;
    }
    for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
   // system("pause");
    return 0;
}