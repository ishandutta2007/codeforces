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
ll x,y,ans;
ll a[2][2000005];
int n,o,p=1;
void cty(ll x,ll y){
           ll O=__gcd(x,y);
           pair<ll,ll> res=mp(0,0);
           for(int i=1;i<=n;i++){
                   pair<ll,ll> ne=mp((y/a[o][i])*a[o][i],a[o][i]);
                   if(ne>res) res=ne;
           }      
           ans+=(y-res.first)/O;
           if(res.first==0) return;
           O=res.second;
           int k=0;
           for(int i=1;i<=n;i++)if(a[o][i]%O==0&&a[o][i]!=O)a[p][++k]=a[o][i];
           n=k;
           o^=1,p^=1;
           cty(x,res.first);
}       
           
int main()
{
    scanf("%I64d%I64d",&x,&y);
    int z=__gcd(x,y);
    for(ll i=1;i<=x;i++){
           if(i*i>x) break;
           if(i*i==x&&i>z&&i%z==0)a[0][++n]=i;
           else if(x%i==0){
                if(i>z&&i%z==0)a[0][++n]=i;
                if((x/i)>z&&(x/i)%z==0)a[0][++n]=x/i;
           }
    }
    sort(a[0]+1,a[0]+n+1);
    cty(x,y);
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}