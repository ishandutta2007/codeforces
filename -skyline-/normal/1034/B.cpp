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
#define orz  2147483647
//:
using namespace std;
int s,t,ans,l[40005],i[40005],q[40005];
struct E{int x,y,z;};
vector<E> v[40005];
void bfs(){
    memset(l,-1,sizeof(l));
    register int qs=0,qe=1;
    q[1]=s,l[s]=0;
    while(qs!=qe){
        register int k=q[++qs];
        for(register int i=0;i<v[k].size();++i){
            register E &o=v[k][i];
            if(o.y&&l[o.x]==-1)l[o.x]=l[k]+1,q[++qe]=o.x;
        }
    }
}
int dfs(int x,int y){
    if(x==t){
        ans+=y;
        return y;
    }
    for(;i[x]<v[x].size();++i[x]){
        register E &o=v[x][i[x]];
        if(o.y&&l[x]+1==l[o.x]){
            register int d=dfs(o.x,min(o.y,y));
            if(d){
                o.y-=d;
                v[o.x][o.z].y+=d;
                return d;
            }
        }
    }
    return 0;
}
void flow(){
    for(;;){
        bfs();
        if(l[t]<0){
            printf("%d\n",ans*2);
            return;
        }
        memset(i,0,sizeof(i));
        while(dfs(s,orz));
    }
}
void add(int x,int y){
    register E X,Y;
    X.x=y,X.y=1,X.z=v[y].size();
    Y.x=x,Y.y=0,Y.z=v[x].size();
    v[x].pb(X),v[y].pb(Y);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m)swap(n,m);
    
    if(n==1){
        int k=(m/6)*6;
        if(m%6==4)k+=2;
        else if(m%6==5)k+=4;
        printf("%d\n",k);
        return 0;
    }/*
    if(n==2){
        if(m%4==0){
            printf("%d\n",2*m);
        }
        else if(m%4==2){
            printf("%d\n",2*m-4);
        }
        else printf("%d\n",2*m-2);
        return 0;
    }
    /*if(n%2==0&&m%2==0){
        printf("%d\n",n*m);
        return 0;
    }*/
    if(n*1ll*m>300ll){
        if(n%2==0||m%2==0){
            printf("%I64d\n",n*1ll*m);
            return 0;
        }
        printf("%I64d\n",n*1ll*m-1ll);
        return 0;
    }
    s=n*m+1;
    t=n*m+2;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if((i+j)&1)add(s,(i-1)*m+j);
            else{
                add((i-1)*m+j,t);
                continue;
            }
            for(int I=1;I<=n;++I){
                for(int J=1;J<=m;++J){
                    if((I+J)&1) continue;
                    if(abs(i-I)+abs(j-J)!=3) continue;
                    add((i-1)*m+j,(I-1)*m+J);
                }
            }
        }
    }
    flow();
	//system("pause");
	return 0;
}