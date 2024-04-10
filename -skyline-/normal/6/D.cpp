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
using namespace std;
int n,A,B,a[12],b[12],c[12],res,ans=orz,l,r,fa[20],fb[20];
int Fa(int x){return x<=0?0:fa[x];}
int Fb(int x){return x<=0?0:fb[x];}
int get(int x,int y,int z){
    if(x>=y&&x>=z) return x;
    if(y>z) return y;
    return z;
}
void go(int x){
    if(x==r){
        b[x]=get(Fb(a[x-1]),Fb(a[x+1]),Fa(a[x]));
        if(res+b[x]<ans){
            ans=res+b[x];
            for(int i=l;i<=r;++i)c[i]=b[i];
        }
        return;
    }
    int p=Fb(a[x-1]),q=Fa(a[x]);
    if(p>=q){
        b[x]=p,a[x-1]-=p*B,a[x]-=p*A,a[x+1]-=p*B,res+=p;
        go(x+1);
        a[x-1]+=p*B,a[x]+=p*A,a[x+1]+=p*B,res-=p;
        return;
    }
    for(int i=p;i<=q;++i){
        b[x]=i,a[x-1]-=i*B,a[x]-=i*A,a[x+1]-=i*B,res+=i;
        go(x+1);
        a[x-1]+=i*B,a[x]+=i*A,a[x+1]+=i*B,res-=i;
    }
}
int main(){
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=18;++i)fa[i]=(i-1)/A+1,fb[i]=(i-1)/B+1;
    for(int i=1;i<=n;++i)scanf("%d",a+i),++a[i];
    while(a[1]>0)a[1]-=B,a[2]-=A,a[3]-=B,++c[1];
    while(a[n]>0)a[n]-=B,a[n-1]-=A,a[n-2]-=B,++c[n];
    l=1;
    while(a[l]<=0&&l<n)++l;
    if(l==n){
        printf("%d\n",c[1]+c[n]);
        for(int i=1;i<=c[1];++i)printf("2 ");
        for(int i=1;i<=c[n];++i)printf("%d ",n-1);
        printf("\n");
        return 0;
    }
    r=n;
    while(a[r]<=0)--r;
    go(l);
    printf("%d\n",ans+c[1]+c[n]);
    c[2]+=c[1],c[n-1]+=c[n];
    for(int i=2;i<n;++i){
        for(int j=1;j<=c[i];++j)printf("%d ",i);
    }
    printf("\n");
//	system("pause");
	return 0;
}