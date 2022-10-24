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
#define X    first
#define Y    second
using namespace std;
int n,a[200005];
pair<int,int> get(int l,int r){
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int x,y;
    scanf("%d%d",&x,&y);
    return mp(x,y);
}
void solve(int l,int r,pair<int,int> p){
    if(r-l+1==p.Y){
        for(int i=l;i<=r;++i)a[i]=p.X;
        return;
    }
    int m=(l+r)/2;
    if(rand()&1){
        pair<int,int> pl=get(l,m);
        if(pl.X==p.X&&pl.Y<p.Y){
            int _l=m-pl.Y+1,_r=_l+p.Y-1;
            for(int i=_l;i<=_r;++i)a[i]=p.X;
            if(l<_l)solve(l,_l-1,get(l,_l-1));
            if(_r<r)solve(_r+1,r,get(_r+1,r));
            return;
        }
        pair<int,int> pr=get(m+1,r);
        if(pr.X==p.X&&pr.Y<p.Y){
            int _r=m+pr.Y,_l=_r-p.Y+1;
            for(int i=_l;i<=_r;++i)a[i]=p.X;
            if(l<_l)solve(l,_l-1,get(l,_l-1));
            if(_r<r)solve(_r+1,r,get(_r+1,r));
            return;
        }
        solve(l,m,pl);
        solve(m+1,r,pr);
    }
    else{
        pair<int,int> pr=get(m+1,r);
        if(pr.X==p.X&&pr.Y<p.Y){
            int _r=m+pr.Y,_l=_r-p.Y+1;
            for(int i=_l;i<=_r;++i)a[i]=p.X;
            if(l<_l)solve(l,_l-1,get(l,_l-1));
            if(_r<r)solve(_r+1,r,get(_r+1,r));
            return;
        }
        pair<int,int> pl=get(l,m);
        if(pl.X==p.X&&pl.Y<p.Y){
            int _l=m-pl.Y+1,_r=_l+p.Y-1;
            for(int i=_l;i<=_r;++i)a[i]=p.X;
            if(l<_l)solve(l,_l-1,get(l,_l-1));
            if(_r<r)solve(_r+1,r,get(_r+1,r));
            return;
        }
        solve(l,m,pl);
        solve(m+1,r,pr);
    }
}
int main(){
    scanf("%d",&n);
    solve(1,n,get(1,n));
    printf("!");
    for(int i=1;i<=n;++i)printf(" %d",a[i]);
    printf("\n");
   // system("pause");
    return 0;
}