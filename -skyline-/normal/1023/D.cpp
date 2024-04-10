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
int n,q,a[200005],b[200005],k,l[200005],r[200005],L[200005],R[200005];
int t[524666];
void upd(int k,int l,int r,int L,int R,int o){
    if(l>R||L>r||l>r) return;
    if(l>=L&&r<=R){
        t[k]=o;
        return;
    }
    int m=(l+r)>>1,lc=k<<1,rc=lc^1;
    if(t[k])t[lc]=t[rc]=t[k],t[k]=0;
    upd(lc,l,m,L,R,o);
    upd(rc,m+1,r,L,R,o);
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        if(!a[i])k=i;
        else{
            if(!l[a[i]])l[a[i]]=i;
            r[a[i]]=i;
        }
    }
    for(int i=1;i<=n;++i){
        if(i==1||a[i-1])L[i]=i;
        else L[i]=L[i-1];
    }
    for(int i=n;i;--i){
        if(i==n||a[i+1])R[i]=i;
        else R[i]=R[i+1];
    }
    for(int i=1;i<=q;++i){
        if(!l[i]) continue;
        upd(1,1,262144,L[l[i]],R[r[i]],i);
    }
    if(!l[q]&&!k){
        puts("NO");
        return 0;
    }
    if(!l[q]){
        upd(1,1,262144,L[k],R[k],q);
    }
    for(int i=1;i<262144;++i)if(t[i])t[i<<1]=t[(i<<1)^1]=t[i];
    for(int i=1;i<=n;++i)b[i]=t[262143+i];
    for(int i=1;i<=n;++i){
        if(!b[i]||(a[i]&&a[i]!=b[i])){
            puts("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=1;i<n;++i)printf("%d ",b[i]);
    printf("%d\n",b[n]);
//	system("pause");
	return 0;
}