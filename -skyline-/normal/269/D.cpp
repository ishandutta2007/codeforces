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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int n,t,h[100005],l[100005],r[100005],ans[100005];
set<pair<int,int> > s,e;
vector<int> v[100005];
vector<pair<int,int> >V;
pair<int,int> p[100005];
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;++i)scanf("%d%d%d",h+i,l+i,r+i),V.pb(mp(l[i],i)),V.pb(mp(r[i],-i));
    h[n+1]=t,l[n+1]=l[n+2]=-orz,r[n+1]=r[n+2]=orz,n+=2,e.insert(mp(n-1,n)),s.insert(mp(t,n-1)),s.insert(mp(0,n)),ans[n]=orz+orz,sort(V.begin(),V.end());
    for(int i=0;i<V.size();++i){
        if(V[i].Y<0)s.erase(mp(h[-V[i].Y],-V[i].Y));
        else{
            set<pair<int,int> >::iterator it=s.lower_bound(mp(h[V[i].Y],V[i].Y));
            int x=(--it)->Y,y=(++it)->Y;
            if(e.count(mp(x,y)))e.erase(mp(x,y));
            e.insert(mp(x,V[i].Y)),e.insert(mp(V[i].Y,y)),s.insert(mp(h[V[i].Y],V[i].Y));
        }
    }
    for(set<pair<int,int> >::iterator it=e.begin();it!=e.end();++it)v[it->X].pb(it->Y);
    for(int i=1;i<=n;++i)p[i]=mp(h[i],i);
    sort(p+1,p+n+1);
    for(int i=1;i<n;++i){
        int x=p[i].Y;
        for(int j=0;j<v[x].size();++j){
            int y=v[x][j];
            ans[y]=max(ans[y],min(ans[x],min(r[x],r[y])-max(l[x],l[y])));
        }
    }
    printf("%d\n",ans[n-1]);        
	//system("pause");
	return 0;
}