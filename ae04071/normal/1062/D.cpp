#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

lli sum[100001];
int pa[100001],n;
int find(int cur){
    return cur==pa[cur] ?cur:pa[cur]=find(pa[cur]);
}
int divv(int u,int v){
    if(u>v)swap(v,u);
    return v/u;
}
void merge(int u,int v){
    int ou=u,ov=v;
    u=find(u),v=find(v);
    if(u!=v){
        pa[v]=u;sum[u]+=sum[v];
    }
    sum[u]+=4*divv(ou,ov);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)pa[i]=i;

    struct td{
        int u,v,d;
        td(){}
        td(int u,int v,int d):u(u),v(v),d(d){}
        bool operator<(const td &rhs)const{
            return d<rhs.d;
        }
    };

    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            merge(i,j);
        }
    }

    lli mx=0;
    for(int i=2;i<=n;i++)if(find(i)==i)
        mx=max(mx,sum[i]);
    printf("%lld\n",mx);

    return 0;
}