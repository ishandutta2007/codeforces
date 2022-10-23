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
struct T{int l,r,x[3],d[3],k[3];}t[100005];
int D,nx[3]={1,2,0},r,L[3],R[3];
bool cmp(T x,T y){return x.k[D]<y.k[D];}
void upd(int k){
    int l=t[k].l,r=t[k].r;
    t[k].x[0]=t[k].d[0]=t[k].k[0];
    t[k].x[1]=t[k].d[1]=t[k].k[1];
    t[k].x[2]=t[k].d[2]=t[k].k[2];
    if(l){
        if(t[l].x[0]<t[k].x[0])t[k].x[0]=t[l].x[0];
        if(t[l].x[1]<t[k].x[1])t[k].x[1]=t[l].x[1];
        if(t[l].x[2]<t[k].x[2])t[k].x[2]=t[l].x[2];
        if(t[l].d[0]>t[k].d[0])t[k].d[0]=t[l].d[0];
        if(t[l].d[1]>t[k].d[1])t[k].d[1]=t[l].d[1];
        if(t[l].d[2]>t[k].d[2])t[k].d[2]=t[l].d[2];
    }
    if(r){
        if(t[r].x[0]<t[k].x[0])t[k].x[0]=t[r].x[0];
        if(t[r].x[1]<t[k].x[1])t[k].x[1]=t[r].x[1];
        if(t[r].x[2]<t[k].x[2])t[k].x[2]=t[r].x[2];
        if(t[r].d[0]>t[k].d[0])t[k].d[0]=t[r].d[0];
        if(t[r].d[1]>t[k].d[1])t[k].d[1]=t[r].d[1];
        if(t[r].d[2]>t[k].d[2])t[k].d[2]=t[r].d[2];
    }
}
int build(int l,int r,int d){
    int m=(l+r)>>1;
    D=d;
    nth_element(t+l+1,t+m+1,t+r+1,cmp);
    if(l<m)t[m].l=build(l,m-1,nx[d]);
    if(r>m)t[m].r=build(m+1,r,nx[d]);
    upd(m);
    return m;
}
int n,m,k,X[3],Y[3];
bool check(int k){
    bool ok=1;
    for(int i=0;i<3&&ok;++i)ok&=(t[k].k[i]>=L[i]&&t[k].k[i]<=R[i]);
    return ok;
}
bool ask(int k){
    bool ok=0;
    for(int i=0;i<3&&!ok;++i)ok|=(t[k].x[i]>R[i]||t[k].d[i]<L[i]);
    if(ok) return 0;
    if(check(k)) return 1;
    if(t[k].l&&ask(t[k].l)) return 1;
    if(t[k].r&&ask(t[k].r)) return 1;
    return 0;
}
int main(){
    scanf("%d%d%d%d%d%d",X,X+1,X+2,&n,&m,&k);
    for(int i=1;i<=n;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        X[0]=min(X[0],x),Y[0]=max(Y[0],x);
        X[1]=min(X[1],y),Y[1]=max(Y[1],y);
        X[2]=min(X[2],z),Y[2]=max(Y[2],z);
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&t[i].k[0],&t[i].k[1],&t[i].k[2]);
        bool ok=1;
        for(int j=0;j<3;++j)ok&=(t[i].k[j]>=X[j]&&t[i].k[j]<=Y[j]);
        if(ok){
            puts("INCORRECT");
            return 0;
        }
    }
    puts("CORRECT");
    r=build(1,m,0);
    for(int i=1;i<=k;++i){
        int o[3];
        scanf("%d%d%d",o,o+1,o+2);
        bool ok=1;
        for(int j=0;j<3;++j)ok&=(o[j]>=X[j]&&o[j]<=Y[j]);
        if(ok){
            puts("OPEN");
            continue;
        }
        for(int j=0;j<3;++j)L[j]=min(X[j],o[j]),R[j]=max(Y[j],o[j]);
        if(ask(r))puts("CLOSED");
        else puts("UNKNOWN");
    }
//	system("pause");
	return 0;
}