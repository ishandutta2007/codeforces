//The past is never dead, it's not even past.
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
#define orz  1000000007ll
#define P    23333333333333333ll
#define Q    1313131ll
#define R    131313131ll
//:
using namespace std;
//
int n;
ll a[1000005],b[1000005];
ll p[1000005],p2[1000005],p3[1000005],p4[1000005],p5[1000005];
int main()
{
    scanf("%d",&n);
    n--;    
    p[0]=p2[0]=p3[0]=p4[0]=p5[0]=1ll;
    for(int i=1;i<=n;i++){
            p[i]=p[i-1]*5%orz;
            p2[i]=p2[i-1]*orz;
            p3[i]=p3[i-1]*61%P;
            p4[i]=p4[i-1]*Q%orz;
            p5[i]=p5[i-1]*R%orz;
    }
    getchar();
    for(int i=1;i<=n;i++){
            char c=getchar();
            if(c=='N')a[i]=1;
            if(c=='S')a[i]=2;
            if(c=='W')a[i]=3;
            if(c=='E')a[i]=4;
    }
    getchar();
    for(int i=1;i<=n;i++){
            char c=getchar();
            if(c=='N')b[i]=2;
            if(c=='S')b[i]=1;
            if(c=='W')b[i]=4;
            if(c=='E')b[i]=3;
    }
    bool ok=1;
    ll k=0,k1=0,k2=0,k3=0,k4=0,K=0,K1=0,K2=0,K3=0,K4=0;
    for(int i=1;i<=n;i++){
            k=(k*5+a[n+1-i])%orz;
            k1=k1*orz+a[n+1-i]; 
            k2=(k2*61+a[n+1-i])%P;  
            k3=(k3*Q+a[n+1-i])%orz;
            k4=(k4*R+a[n+1-i])%orz;
            K=(K+p[i-1]*b[n+1-i]%orz)%orz;
            K1=K1+p2[i-1]*b[n+1-i];
            K2=(K2+p3[i-1]*b[n+1-i]%P)%P;  
            K3=(p4[i-1]*b[n+1-i]%orz+K3)%orz;
            K4=(p5[i-1]*b[n+1-i]%orz+K4)%orz;
            if(k==K&&k1==K1&&k2==K2&&k3==K3&&k4==K4) ok=0;
    }
    if(ok)puts("YES");
    else puts("NO");
//	system("pause");
	return 0;
}