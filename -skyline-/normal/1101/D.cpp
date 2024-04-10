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
#pragma GCC optimize("Ofast")
using namespace std;
int n,a[200005],p[200005],d[200005],vi[200005],cnt,nw[200005],q[200005],ans;
vector<int> v[200005],con[200005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i),con[a[i]].pb(i);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=2;i<=200000;++i){
        if(p[i]) continue;
        for(int j=i*2;j<=200000;j+=i)p[j]=1;
        int k=0;
        for(int j=i;j<=200000;j+=i){
            for(int _=0;_<con[j].size();++_)q[++k]=con[j][_];
        }
        for(int j=1;j<=k;++j){
            if(nw[q[j]]==i) continue;
            queue<int> Q;
            ++cnt;
            Q.push(q[j]);
            d[q[j]]=1;
            vi[q[j]]=cnt;
            int _=q[j];
            while(!Q.empty()){
                int x=Q.front();
                Q.pop();
                _=x;
                nw[x]=i;
                for(int I=0;I<v[x].size();++I){
                    int y=v[x][I];
                    if(a[y]%i==0&&vi[y]!=cnt){
                        vi[y]=cnt;
                        d[y]=d[x]+1;
                        Q.push(y);
                    }
                }
            }
            ++cnt;
            Q.push(_);
            d[_]=1;
            vi[_]=cnt;
            while(!Q.empty()){
                int x=Q.front();
                Q.pop();
                _=x;
                for(int I=0;I<v[x].size();++I){
                    int y=v[x][I];
                    if(a[y]%i==0&&vi[y]!=cnt){
                        vi[y]=cnt;
                        d[y]=d[x]+1;
                        Q.push(y);
                    }
                }
            }
            ans=max(ans,d[_]);
        }
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}