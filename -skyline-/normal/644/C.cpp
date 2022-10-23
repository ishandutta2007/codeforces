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
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int n,k;
string s,q;
pair<pair<ll,ll>,pair<ll,ll> > ha[100005];
string qwe[100005];
map<string,int> m;
pair<pair<pair<ll,ll>,pair<ll,ll> >,int> l[100005];
int ans;
set<pair<pair<ll,ll>,pair<ll,ll> > >ss[100005];
vector<pair<pair<ll,ll>,pair<ll,ll> > >vs[100005];
vector<int> res[100005];
ll cty(int w){
           ll t=12327+4293*w,ans=0;
           for(int i=0;i<q.size();i++)ans=ans*t+q[i]+23;
           return ans;
}
int get(){
    if(m.count(s)) return m[s];
    m[s]=++k;
    qwe[k]=s;
    return k;
}
pair<pair<ll,ll>,pair<ll,ll> > dtx(pair<pair<ll,ll>,pair<ll,ll> > q,pair<pair<ll,ll>,pair<ll,ll> > w){
                             q.X.X=q.X.X*orz+w.X.X;
                             q.X.Y=q.X.Y*orz+w.X.Y;
                             q.Y.X=q.Y.X*orz+w.Y.X;
                             q.Y.Y=q.Y.Y*orz+w.Y.Y;
                             return q;
}
                             
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
            string p;
            cin>>p;
            s="";
            q="";
            int b=0;
            for(int i=0;i<p.size();i++){
                    if(p[i]=='/')b++;
                    if(b>2)q+=p[i];
                    else s+=p[i];
            }
            int z=get();
            pair<pair<ll,ll>,pair<ll,ll> >pl=mp(mp(cty(1),cty(2)),mp(cty(3),cty(4)));
            if(b==2)pl=mp(mp(-12321,-15465),mp(-14545,-10111));

            if(!ss[z].count(pl))ss[z].insert(pl),vs[z].pb(pl);
    }
    for(int i=1;i<=k;i++)sort(vs[i].begin(),vs[i].end());
    for(int i=1;i<=k;i++)for(int j=0;j<vs[i].size();j++)ha[i]=dtx(ha[i],vs[i][j]);
    for(int i=1;i<=k;i++)l[i]=mp(ha[i],i);
    sort(l+1,l+k+1);
    for(int i=1;i<=k;i++){
            int j=i;
            while(l[j+1].first==l[j].first&&j!=k)j++;
            if(i!=j){
                     ans++;
                     for(int v=i;v<=j;v++)res[ans].pb(l[v].second);
            }
            i=j;
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
            int o=res[i].size();
            for(int j=0;j<o-1;j++)cout<<qwe[res[i][j]]<<' ';
            cout<<qwe[res[i][o-1]]<<'\n';
    }
	return 0;       
}