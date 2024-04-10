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
int Q,n;
ll f[400005][20],w[400005][20],p[400005][20],q[400005][20],last;
int main(){
    scanf("%d",&Q);
    n=1;
    while(Q--){
        int t;
        ll x,y;
        scanf("%d%I64d%I64d",&t,&x,&y);
        x^=last,y^=last;
        if(t==1){
            n++;
            f[n][0]=w[n][0]=y;
            p[n][0]=x;
            for(int i=0;i<19;i++)p[n][i+1]=p[p[n][i]][i];
            for(int i=0;i<19;i++)f[n][i+1]=max(f[n][i],f[p[n][i]][i]);
            for(int i=19;i>=0;i--)if(f[x][i]<y)x=p[x][i];
            if(w[x][0]<y)x=p[x][0];
            q[n][0]=x;
            for(int i=0;i<19;i++)q[n][i+1]=q[q[n][i]][i];
            for(int i=0;i<19;i++)w[n][i+1]=w[n][i]+w[q[n][i]][i];
            continue;
        }
        if(w[x][0]>y){
            printf("0\n");
            last=0;
            continue;
        }
        int ans=0;
        for(int i=19;i>=0;i--)if(w[x][i]<=y&&q[x][i])y-=w[x][i],x=q[x][i],ans+=(1<<i);
        if(w[x][0]<=y)ans++;
        printf("%d\n",ans);
        last=ans;
    }
	//system("pause");
	return 0;
}