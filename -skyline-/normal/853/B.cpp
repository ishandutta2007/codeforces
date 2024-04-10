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
ll x[1000005],y[1000005],s,ans=-1;
int n,m,k,c;
vector<pair<int,int> > v1[1000005],v2[1000005];
map<int,int>M;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
            int d,f,t,c;
            scanf("%d%d%d%d",&d,&f,&t,&c);
            if(!t)v1[d].pb(mp(f,c));
            else v2[d].pb(mp(t,c));
    }
    for(int i=1;i<=1000000;i++){
            if(!v1[i].size()) continue;
            for(int j=0;j<v1[i].size();j++){
                    int p=v1[i][j].first,q=v1[i][j].second;
                    if(!M[p])c++,s+=q*1ll,M[p]=q;
                    else if(M[p]>q)s=s-M[p]*1ll+q*1ll,M[p]=q;
            }
            if(c==n)x[i]=s;
    }
    c=0;
    s=0;
    M.clear();
    for(int i=1000000;i>=1;i--){
            for(int j=0;j<v2[i].size();j++){
                    int p=v2[i][j].first,q=v2[i][j].second;
                    if(!M[p])c++,s+=q*1ll,M[p]=q;
                    else if(M[p]>q)s=s-M[p]*1ll+q*1ll,M[p]=q;
            }
            if(c==n)y[i]=s;
    }
    for(int i=1;i<=1000000;i++){
            if(i+k+1>1000000) break;
            if(x[i]==0||y[i+k+1]==0) continue;
            if(ans==-1)ans=x[i]+y[i+k+1];
            else ans=min(ans,x[i]+y[i+k+1]);
    }
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}