// Author: wlzhouzhuan
#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=35005;

ll pre[N],a[N],L[N],R[N];
int n;

ll check(ll give){
    priority_queue<ll>pq1;
    priority_queue<ll,vector<ll>,greater<ll>>pq2;
    ll nowL=give,nowR=give,ans=0;
    rep(i,1,n+1)pq1.push(0),pq2.push(0);
    rep(i,1,n){
        nowL+=L[i],nowR+=R[i];
        ll curL=pq1.top()+nowL,curR=pq2.top()+nowR;
//        printf("i = %d, curL=%lld,curR=%lld, ans=%lld\n",i,curL,curR,ans);
//        printf("nowL=%lld,nowR=%lld\n",nowL,nowR);
        if(curL<=pre[i]&&pre[i]<=curR){
            pq1.push(pre[i]-nowL);
            pq2.push(pre[i]-nowR);
        }else if(pre[i]<curL){
            ans+=curL-pre[i];
            pq2.push(curL-nowR),pq1.pop();
            pq1.push(pre[i]-nowL);
            pq1.push(pre[i]-nowL);
        }else{
//            printf("here!\n");
            ans+=pre[i]-curR;
            pq1.push(curR-nowL),pq2.pop();
            pq2.push(pre[i]-nowR);
            pq2.push(pre[i]-nowR);
        }
        curL=pq1.top()+nowL,curR=pq2.top()+nowR;
//        printf("i=%d,curL=%lld,curR=%lld\n",i,curL,curR);
//        priority_queue<ll> tmp=pq1;
//        while(!tmp.empty()){
//            printf("%d ",tmp.top()+nowL);tmp.pop();
//        }puts("");
//        priority_queue<ll,vector<ll>,greater<ll>> tmq=pq2;
//        while(!tmq.empty()){
//            printf("%d ",tmq.top()+nowR);tmq.pop();
//        }puts("");
    }
    //  aim 
    ll curL=pq1.top()+nowL,curR=pq2.top()+nowR;
    ll aim=pre[n]+give;
//    printf("curL=%lld,curR=%lld,aim=%lld\n",curL,curR,aim);
//    printf("ans=%lld\n",ans);
    if(aim<curL){
        while(SZ(pq1)){
            ll pos=pq1.top()+nowL;
            if(pos<=aim)break;
            ans+=pos-aim;
            pq1.pop();
        }
    }else if(aim>curR){
        while(SZ(pq2)){
            ll pos=pq2.top()+nowR;
            if(pos>=aim)break;
            ans+=aim-pos;
            pq2.pop();
        }
    } 
//    printf("ans=%lld\n",ans);
    return ans;
}

int main(){
    n=read();
    rep(i,1,n){
        a[i]=read(),L[i]=read(),R[i]=read();
        pre[i]=pre[i-1]+a[i];
    }
//    rep(i,-30,30){
//        printf("When i=%d,",i);
//        check(i);
//    }
//    return 0;
    
    ll l=-1e12,r=1e12;
    while(l+6<r){
        ll mid=(l+r)/2;
        if(check(mid)<check(mid+1))r=mid+1;
        else l=mid;
    }
    ll ans=1e18;
    rep(i,l,r)ckmin(ans,check(i));
    print(ans,'\n');
    return 0;
}

/*
3
3 2 5
4 2 6
1 0 1
*/