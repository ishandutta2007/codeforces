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
#include<Windows.h>
using namespace std;
#define LL    long long
int a[200005],p[200005],rank[200005],n,m;
long long ans;
vector<pair<int,pair<int,int> > > v;

inline int ope(int x){return x==p[x]?x:p[x]=ope(p[x]);}

inline void un(int x,int y){
       int ox=ope(x),oy=ope(y);
       if(rank[ox]>rank[oy]){
                             p[oy]=p[ox];
                             rank[ox]+=rank[oy];
       }
       else{
            p[ox]=p[oy];
            rank[oy]+=rank[ox];
       }
}
       
                                  
int main()
{
    int i,j,k,l;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i],p[i]=i,rank[i]=1;
    for(i=1;i<=m;i++){
                      cin>>j>>k;
                      v.push_back(make_pair(min(a[j],a[k]),make_pair(j,k)));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(i=0;i<m;i++){
                            int ox=ope(v[i].second.first),oy=ope(v[i].second.second);
                            if(ox==oy) continue;
                            long long lo=1LL*v[i].first*rank[ox]*rank[oy];
                            ans+=lo;
                            un(ox,oy);
                            //cout<<i<<'-'<<ans<<"_____"<<v[i].first<<"{}"<<v[i].second.first<<"~!~!"<<v[i].second.second<<endl;
    }
    
    double d=(ans*2.0/(n*1.0)/(n*1.0-1.0));
    cout.precision(12);
    cout<<fixed<<d*1.0000000000<<endl;
                            
    //system("pause");
    return 0;
}