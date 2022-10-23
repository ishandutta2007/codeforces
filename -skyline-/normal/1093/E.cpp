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



int n,m,b[200005],p[200005];

int get(){
    register char c=getchar();
    register int o=0;
    while(c<48)c=getchar();
    while(c>47)o=o*10+c-48,c=getchar();
    return o;
}

int O[20],B;
void out(int x){
     if(!x){
            puts("0");
            return;
     }
     while(x)O[++B]=x%10,x/=10;
     while(B)putchar(O[B--]+48);
     putchar('\n');
}

int ku[200005],sz[205],a[205][1005];
int fnd(int k,int x){
    int O=0;
    for(int i=9;i>=0;--i){
        int o=O+(1<<i);
        if(o<=sz[k]&&a[k][o]<=x)O=o;
    }
    return O;
}
int main(){
    n=get();m=get();
    for(int i=1;i<=n;++i)p[get()]=i;
    for(int i=1;i<=n;++i)b[i]=p[get()];
    for(int i=1;i<=n;++i){
        ku[i]=(i-1)/1000+1;
        a[ku[i]][++sz[ku[i]]]=b[i];
    }
    for(int i=1;i<=200;++i)sort(a[i]+1,a[i]+sz[i]+1);
    while(m--){
        int T;
        T=get();
        if(T==2){
            int x,y,X,Y;
            x=get();y=get();
            X=b[x],Y=b[y];
            if(ku[x]!=ku[y]){
                int o=ku[x],S=sz[x],P=fnd(o,X),k=fnd(o,Y)+1;
                if(k==P||k==P+1)a[o][P]=Y;
                else if(k<P){
                    for(int i=P;i>k;--i)a[o][i]=a[o][i-1];
                    a[o][k]=Y;
                }
                else{
                    --k;
                    for(int i=P;i<k;++i)a[o][i]=a[o][i+1];
                    a[o][k]=Y;
                }
                o=ku[y],S=sz[y],P=fnd(o,Y),k=fnd(o,X)+1;
                if(k==P||k==P+1)a[o][P]=X;
                else if(k<P){
                    for(int i=P;i>k;--i)a[o][i]=a[o][i-1];
                    a[o][k]=X;
                }
                else{
                    --k;
                    for(int i=P;i<k;++i)a[o][i]=a[o][i+1];
                    a[o][k]=X;
                }
            }
            swap(b[x],b[y]);
            continue;
        }
        int ans=0;
        int la,ra,lb,rb;
        la=get();ra=get();lb=get();rb=get();
        int L=ku[lb],R=ku[rb];
        if(L==R){
            for(int i=lb;i<=rb;++i)if(b[i]<=ra&&b[i]>=la)++ans;
        }
        else{
            for(int i=L*1000;i>=lb;--i)if(b[i]<=ra&&b[i]>=la)++ans;
            ++L;
            for(int i=R*1000-999;i<=rb;++i)if(b[i]<=ra&&b[i]>=la)++ans;
            --R;
            for(int i=L;i<=R;++i)ans+=fnd(i,ra)-fnd(i,la-1);
        }
        out(ans);
    }
//	system("pause");
	return 0;
}