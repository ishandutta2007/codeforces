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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int D,s,f[505][5005],d[2600005],r[2600005],la[2600005],wy[2600005],cnt;
vector<int> Q[2600005];
pair<int,int> P[2600005];
void out(int x){
    if(d[x]){
        out(la[x]);
        putchar(48+wy[x]);
    }
}
int main(){
    scanf("%d%d",&D,&s);
    for(int i=0;i<D;++i){
        for(int j=0;j<=s;++j){
            f[i][j]=++cnt;
        }
    }
    memset(d,-1,sizeof(d));
    d[1]=0;
    Q[0].pb(1);
    for(int _=0;Q[_].size();++_){
        cnt=0;
        for(int i=0;i<Q[_].size();++i){
            int k=Q[_][i];
            P[++cnt]=mp(r[la[k]]*10+wy[k],k);
        }
        Q[_].clear();
        sort(P+1,P+cnt+1);
        int k=0;
        for(int i=1;i<=cnt;++i){
            if(i==1||P[i].first!=P[i-1].first)++k;
            r[P[i].second]=k;
        }
        for(int i=1;i<=cnt;++i){
            int x=P[i].second,I,J;
            J=(x-1)%(s+1),I=(x-J)/(s+1);
            vector<int> v,e;
            for(int k=0;k<10&&J+k<=s;++k){
                int f2=f[(I*10+k)%D][J+k];
                v.pb(f2);
                e.pb(k);
            }
            for(int j=0;j<v.size();++j){
                int y=v[j];
                if(d[y]==-1){
                    d[y]=_+1;
                    Q[_+1].pb(y);
                    la[y]=x;
                    wy[y]=e[j];
                }
                else if(d[y]==_+1){
                    if(r[la[y]]*10+wy[y]>r[x]*10+e[j]){
                        la[y]=x;
                        wy[y]=e[j];
                    }
                }
            }
        }
    }
    int k=f[0][s];
    if(d[k]==-1){
        puts("-1");
    }
    else{
        out(k);
        putchar('\n');
    }
//	system("pause");
	return 0;
}