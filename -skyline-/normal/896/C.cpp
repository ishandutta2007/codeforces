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
#define T    map<int,long long>::iterator
#define X    first
#define Y    second
#define ub   upper_bound
#define lb   lower_bound
//:
using namespace std;
ll seed;
int n,m;
ll x,y,v;
map<int,ll> M;
ll rnd(){
    ll ret=seed;
    seed=(seed*7ll+13)%1000000007ll;
    return ret;
}
ll fpower(ll o){
    ll ans=1,k=x;
    o%=y;
    while(k){
             if(k&1ll)ans=ans*o%y;
             k/=2ll;
             o=o*o%y;
    }
    return ans;
}
int main()
{
    scanf("%d%d%I64d%I64d",&n,&m,&seed,&v);
    for(int i=1;i<=n;++i)M[i]=(rnd()%v)+1;
    M[n+1]=0;
    for(int _=1;_<=m;++_){
            int op=rnd()%4+1;
            ll l=rnd()%n+1,r=rnd()%n+1;
            if(l>r) swap(l,r);
            if(op==3)x=(rnd()%(r-l+1))+1;
            else x=(rnd()%v)+1;
            if(op==4)y=rnd()%v+1;
            T it=--M.ub(l);
            M[l]=it->Y;
            it=--M.ub(r+1);
            M[r+1]=it->Y;
            if(op==1){
                      it=M.lb(l);
                      while(it->X!=r+1)it->Y+=x,++it;
                      continue;
            }
            if(op==2){
                      it=M.lb(l);
                      while(it->X!=r+1)M.erase(it),it=M.lb(l);
                      M[l]=x;
                      continue;
            }
            if(op==3){
                      vector<pair<ll,int> >v;
                      it=M.lb(l);
                      while(it->X!=r+1){
                                        T it2=it;
                                        it2++;
                                        v.pb(mp(it->Y,it2->X-it->X));
                                        it=it2;
                      }
                      sort(v.begin(),v.end());
                      int o=0;          
                      for(int i=0;i<v.size();i++){
                              o+=v[i].Y;
                              if(o>=x){
                                       printf("%I64d\n",v[i].X);
                                       break;
                              }
                      }
                      continue;
            }
            it=M.lb(l);
            ll ans=0;
            while(it->X!=r+1){
                              T it2=it;
                              it2++;
                              ans=(ans+fpower(it->Y)*(it2->X-it->X))%y;
                              it=it2;
            }
            printf("%I64d\n",ans);
    }
//	system("pause");
	return 0;
}