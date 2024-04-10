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
#define K    262144
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
//262144
//524288
using namespace std;
ll n,m,a[524400],b[524400];
void inc(int k,int l,int r,int L,int R,int x){
     if(r<L||l>R) return;
     if(l>=L&&r<=R){
                    b[k]+=x;
                    return;
     }
     int m=(l+r)>>1;
     inc(k<<1,l,m,L,R,x);
     inc((k<<1)^1,m+1,r,L,R,x);
     a[k]=min(a[k<<1]+b[k<<1],a[(k<<1)^1]+b[(k<<1)^1]);
}

ll cty(int k,int l,int r,int L,int R){
  if(r<L||l>R) return orz;           
  if(l>=L&&r<=R) return a[k]+b[k];
  int m=(l+r)>>1;
  return min(cty(k<<1,l,m,L,R),cty((k<<1)^1,m+1,r,L,R))+b[k];
}

int main()
{     
    scanf("%I64d",&n);
    for(int i=K;i<=K<<1;i++)a[i]=orz;
    for(int i=1;i<=n;i++)scanf("%I64d",a+K-1+i);
    for(int i=K-1;i;i--)a[i]=min(a[i<<1],a[(i<<1)^1]);
    scanf("%I64d",&m);
    for(int i=1;i<=m;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            l++,r++;
            char c=getchar();
            if(c==' '){
                    ll x;
                    scanf("%I64d",&x);
                    if(l<=r) inc(1,1,K,l,r,x);
                    else inc(1,1,K,l,n,x),inc(1,1,K,1,r,x);
            }
            else if(l<=r)printf("%I64d\n",cty(1,1,K,l,r));
            else printf("%I64d\n",min(cty(1,1,K,l,n),cty(1,1,K,1,r)));
    }
//	system("pause");
	return 0;
}