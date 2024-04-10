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
using namespace std;
struct T{
    int t[524300],L,R;
    void upd(int x,int k){
        k+=262143;
        t[k]=x;
        k>>=1;
        while(k)t[k]=max(t[k<<1],t[(k<<1)^1]),k>>=1;
    }
    int get(int k,int l,int r){
        if(l>=L&&r<=R) return t[k];
        int m=(l+r)>>1,lc=k<<1,rc=lc^1;
        if(L>m) return get(rc,m+1,r);
        if(R<=m) return get(lc,l,m);
        return max(get(lc,l,m),get(rc,m+1,r));
    }
    int qry(int l,int r){
        L=l,R=r;
        return get(1,1,262144);
    }
    void bld(){
        for(int i=262143;i;--i)t[i]=max(t[i<<1],t[(i<<1)^1]);
    }
}t[32];
int n,k,q,a[200005][5],res[32];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j)scanf("%d",a[i]+j);
    }
    for(int _=0;_<(1<<k);++_){
        for(int i=1;i<=n;++i){
            int o=0;
            for(int j=0;j<k;++j){
                if(_&(1<<j))o+=a[i][j];
                else o-=a[i][j];
            }
            t[_].t[i+262143]=o;
        }
        for(int i=n+262144;i<=524287;++i)t[_].t[i]=-orz;
        t[_].bld();
    }
    scanf("%d",&q);
    while(q--){
        int ty;
        scanf("%d",&ty);
        if(ty==1){
            int x;
            scanf("%d",&x);
            for(int i=0;i<k;++i)scanf("%d",a[x]+i);
            for(int _=0;_<(1<<k);++_){
                int o=0;
                for(int i=0;i<k;++i){
                    if(_&(1<<i))o+=a[x][i];
                    else o-=a[x][i];
                }
                t[_].upd(o,x);
            }
        }
        else{
            int l,r,_=(1<<k)-1,ans=0;
            scanf("%d%d",&l,&r);
            for(int i=0;i<=_;++i)res[i]=t[i].qry(l,r);
            for(int i=0;i<=_;++i)ans=max(ans,res[i]+res[_^i]);
            printf("%d\n",ans);
        }
    }
//	system("pause");
	return 0;
}