#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 524288
struct point{
    long long A, B;
    int num;
    bool operator <(const point &p)const{
        return A!=p.A?A>p.A:num<p.num;
    }
}w[301000];
int n, st, Num[301000];
long long INF = 2e18;
struct Order{
    int num;
    long long g;
    bool operator<(const Order &p)const{
        return g<p.g;
    }
}ord[301000];
struct Tree{
    long long S;
    int cc;
}IT[SZ+SZ+2];
void UDT(int nd){
    IT[nd].cc = IT[nd*2].cc+IT[nd*2+1].cc;
    IT[nd].S = IT[nd*2].S + IT[nd*2+1].S;
    IT[nd].S = min(IT[nd].S, INF);
}
void Ins(int nd, int b, int e, int x){
    if(b==e){
        IT[nd].S += ord[x].g;
        IT[nd].cc++;
        return;
    }
    int m = (b+e)>>1;
    if(x<=m)Ins(nd*2,b,m,x);
    else Ins(nd*2+1,m+1,e,x);
    UDT(nd);
}
int Get(int nd, int b, int e, long long C){
    if(IT[nd].S <= C){
        return IT[nd].cc;
    }
    if(b==e)return 0;
    int m =(b+e)>>1, r = 0;
    if(IT[nd*2].S <= C){
        C-=IT[nd*2].S;
        r+=IT[nd*2].cc;
        return r+Get(nd*2+1,m+1,e,C);
    }
    return Get(nd*2,b,m,C);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld%lld",&w[i].A,&w[i].B);
        w[i].num = i;
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        if(w[i].num == 1)break;
    }
    st = i;
    for(i=1;i<=n;i++){
        ord[i].num = i;
        ord[i].g = w[i].B-w[i].A+1;
    }
    sort(ord+1,ord+n+1);
    for(i=1;i<=n;i++)Num[ord[i].num] = i;
    for(i=1;i<st;i++){
        Ins(1, 1, SZ, Num[i]);
    }
    int res = st;
    for(i=st+1;i<=n+1;i++){
        int t = Get(1, 1, SZ, w[st].A - w[i].A);
        res = min(res, i-1-t);
        if(i==n+1)break;
        Ins(1, 1, SZ, Num[i]);
    }
    printf("%d\n",res);
}