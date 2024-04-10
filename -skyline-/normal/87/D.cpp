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
//:
using namespace std;
//
//
int n,f[100005],s[200005],o[100005],k;
pair<pair<int,int>,pair<int,int> >p[100005];
vector<int> v[200005],e[200005];
ll ans[100005];                                
int u[200005],u2[200005],S;
vector<int> out;
ll MAX;
int cty(int x){return f[x]==x?x:f[x]=cty(f[x]);}
int OPE(int x,int y){
    int sum=0;
    u2[x]=y;
    for(int i=0;i<v[x].size();i++){
            if(u2[v[x][i]]==y) continue;
            sum+=OPE(v[x][i],y);
    }
    return sum+s[x];
}
int ope(int x,int y){ 
    int sum=0;
    u[x]=y;
    for(int i=0;i<v[x].size();i++){
            if(u[v[x][i]]==y) continue;
            int O=ope(v[x][i],y);
            ans[e[x][i]]=O*1ll*(S*1ll-O);
            sum+=O;
    }
    return sum+s[x];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
            scanf("%d%d%d",&p[i].Y.X,&p[i].Y.Y,&p[i].X.X);
            p[i].X.Y=i;
    }
    sort(p+1,p+n);
    k=n;
    for(int i=1;i<=n;i++)f[i]=i,s[i]=1,o[i]=i;
    for(int i=1;i<n;i++){
            int I=i;
            while(p[I+1].X.X==p[i].X.X)I++;
            for(int j=i;j<=I;j++){
                    v[o[cty(p[j].Y.X)]].pb(o[cty(p[j].Y.Y)]);
                    v[o[cty(p[j].Y.Y)]].pb(o[cty(p[j].Y.X)]);
                    e[o[cty(p[j].Y.X)]].pb(p[j].X.Y);
                    e[o[cty(p[j].Y.Y)]].pb(p[j].X.Y);
            }
            for(int j=i;j<=I;j++){
                    if(u[o[cty(p[j].Y.X)]]!=i){
                                               S=OPE(o[cty(p[j].Y.X)],i);
                                               ope(o[cty(p[j].Y.X)],i);
                    }
            }
            for(int j=i;j<=I;j++){
                    v[o[cty(p[j].Y.X)]].pop_back();
                    v[o[cty(p[j].Y.Y)]].pop_back();
                    e[o[cty(p[j].Y.X)]].pop_back();
                    e[o[cty(p[j].Y.Y)]].pop_back();
            }
            for(int j=i;j<=I;j++){
                    s[++k]=s[o[cty(p[j].Y.X)]]+s[o[cty(p[j].Y.Y)]];
                    f[f[p[j].Y.Y]]=f[p[j].Y.X];
                    o[f[p[j].Y.X]]=k;
            }
            i=I;
    }
    for(int i=1;i<=n;i++){
            if(ans[i]>MAX){
                           MAX=ans[i];
                           out.clear();
            }
            if(ans[i]==MAX) out.pb(i);
    }
    printf("%I64d %d\n",MAX*2ll,out.size());
    for(int i=0;i<out.size();i++)printf("%d ",out[i]);
    printf("\n");
//	system("pause");
	return 0;
}