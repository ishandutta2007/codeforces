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
int n,m,ans;
ll a[205];
pair<int,int> p[205];
int f[2][205][6000];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%I64d",a+i);
    for(int i=1;i<=n;i++){
            int x=0,y=0;
            while(a[i]%2ll==0)a[i]/=2ll,x++;
            while(a[i]%5ll==0)a[i]/=5ll,y++;
            p[i]=mp(x-y,y);
    }
    sort(p+1,p+n+1);
    memset(f,-1,sizeof(f));
    f[0][0][0]=0;
    for(int i=1;i<=n;i++){
            int c=i&1,o=c^1;
            for(int j=0;j<i;j++){
                    if(j==m) break;
                    for(int k=j*27;k>=0;k--){
                            if(f[o][j][k]==-1) continue;
                            if(f[c][j][k]==-1||f[c][j][k]<f[o][j][k])f[c][j][k]=f[o][j][k];
                            int K=max(0,k-p[i].X),O=p[i].Y+f[o][j][k];
                            if(f[c][j+1][K]==-1||f[c][j+1][K]<O)f[c][j+1][K]=O;
                            ans=max(ans,O-K);
                    }
            }
    }
    printf("%d\n",ans);        
//	system("pause");
	return 0;
}