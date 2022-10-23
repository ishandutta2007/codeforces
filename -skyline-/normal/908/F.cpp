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
//:
using namespace std;
pair<int,int> p[300005];
int n,cnt,ans;
void calc(int x,int y){
    int X=0,Y=0,o=x;
    for(int i=x+1;i<=y;i++)if(p[i].second!=2)X=max(X,p[i].first-p[o].first),o=i;
    o=x;
    for(int i=x+1;i<=y;i++)if(p[i].second!=1)Y=max(Y,p[i].first-p[o].first),o=i;
    o=p[y].first-p[x].first;
    if(X+Y>o)ans+=(o-X+o-Y+o);
    else ans+=o*2;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char c;
        scanf("%d %c",&p[i].first,&c);
        if(c=='G')cnt++;
        else if(c=='R')p[i].second=1;
        else p[i].second=2;
    }
    if(!cnt){
        int rl=0,rr=0,bl=0,br=0;
        for(int i=1;i<=n;i++){
            if(p[i].second==1){
                if(!rl)rl=p[i].first;
                rr=p[i].first;
            }
            else{
                if(!bl)bl=p[i].first;
                br=p[i].first;
            }
        }
        printf("%d\n",rr+-rl+br-bl);
        return 0;
    }
    int L=1,R=n;
    while(p[L].second)L++;
    while(p[R].second)R--;
    for(int i=1;i<L;i++)if(p[i].second==1)ans+=p[L].first-p[i].first,i=L;
    for(int i=1;i<L;i++)if(p[i].second==2)ans+=p[L].first-p[i].first,i=L;
    for(int i=n;i>R;i--)if(p[i].second==1)ans+=p[i].first-p[R].first,i=R;
    for(int i=n;i>R;i--)if(p[i].second==2)ans+=p[i].first-p[R].first,i=R;
    for(int i=L+1;i<=R;i++)if(!p[i].second)calc(L,i),L=i;
    printf("%d\n",ans);
//	system("pause");
	return 0;
}