#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define SZ 262144
#define pii pair<int,int>
using namespace std;
int n, Q, w[201000];
int cc;
long long ss;
struct Tree{
    long long Mn[SZ+SZ], K[SZ+SZ], Sum[SZ+SZ], Mx[SZ+SZ];
    void UDT(int nd){
        Mn[nd]=min(Mn[nd*2],Mn[nd*2+1]);
        Mx[nd]=max(Mx[nd*2],Mx[nd*2+1]);
        Sum[nd]=Sum[nd*2]+Sum[nd*2+1];
    }
    void init(int nd, int b, int e){
        K[nd]=0;
        if(b==e){
            Mx[nd]=Mn[nd]=Sum[nd]=w[b];
            return;
        }
        int m =(b+e)>>1;
        init(nd*2,b,m);
        init(nd*2+1,m+1,e);
        UDT(nd);
    }
    void Put2(int nd, int b, int e, long long x){
        Mx[nd]=Mn[nd]=x;
        Sum[nd]=x*(e-b+1);
        K[nd] = x;
    }
    void Spread(int nd, int b, int e, int m){
        if(K[nd]){
            Put2(nd*2,b,m,K[nd]);
            Put2(nd*2+1,m+1,e,K[nd]);
            K[nd]=0;
        }
    }
    void Put(int nd, int b, int e, int s, int l, long long y){
        if(s>l)return;
        if(s<=b && e<=l){
            if(Mn[nd] >= y)return;
            if(Mx[nd] <= y){
                Put2(nd,b,e,y);
                return;
            }
        }
        int m = (b+e)>>1;
        Spread(nd,b,e,m);
        if(s<=m)Put(nd*2,b,m,s,l,y);
        if(l>m)Put(nd*2+1,m+1,e,s,l,y);
        UDT(nd);
    }
    int Find(int nd, int b, int e, int x){
        if(Mn[nd] > x)return n+1;
        if(b==e)return b;
        int m = (b+e)>>1;
        Spread(nd,b,e,m);
        if(Mn[nd*2]<=x)return Find(nd*2,b,m,x);
        return Find(nd*2+1,m+1,e,x);
    }
    long long Go(int nd, int b, int e, int s, int M){
        //printf("%d %d %d %d %d %lld %lld\n",nd,b,e,s,M,Mn[nd],Sum[nd]);
        if(Mn[nd]>M)return 0ll;
        if(e<s)return 0ll;
        if(s<=b && Sum[nd]<=M){
            cc+=e-b+1;
            ss+=Sum[nd];
            return Sum[nd];
        }
        int m = (b+e)>>1;
        Spread(nd,b,e,m);
        long long rr = 0;
        if(s<=m){
            long long tt = Go(nd*2,b,m,s,M);
            M-=tt;
            rr += tt;
        }
        rr += Go(nd*2+1,m+1,e,s,M);
        return rr;
    }
}T;
int main(){
    int i;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    T.init(1,1,n);
    while(Q--){
        int ck, a, b;
        scanf("%d%d%d",&ck,&a,&b);
        if(ck==1){
            T.Put(1,1,n,1,a,b);
            continue;
        }
        else{
            ss=cc=0;
            T.Go(1,1,n,a,b);
            printf("%d\n",cc);
        }
        /*
        while(1){
            int z = T.Find(1,1,n,b);
            z=max(z,a);
            if(z==n+1)break;
            cc=0;
            ss=0;
            a=z;
            T.Go(1,1,n,a,b);
            b-=ss;
            a+=cc;
        }
        */
    }
}