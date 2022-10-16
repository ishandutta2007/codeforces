// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

const int N=10005;

ll a[N],ans;
int L[N],R[N];
int n;

int main(){
    n=read();rep(i,1,n)a[i]=read();
    rep(i,1,n){
        L[i]=R[i]=i;
        while(L[i]>0&&a[L[i]]>=a[i])L[i]--;
        while(R[i]<=n&&a[R[i]]>=a[i])R[i]++;
    }
    // 
    rep(i,0,n){
        ll mx1=0,mx2=0;
        rep(j,1,i)ckmax(mx1,1ll*a[j]*(min(i+1,R[j])-L[j]-1));
        rep(j,i+1,n)ckmax(mx2,1ll*a[j]*(R[j]-max(i,L[j])-1));
        ckmax(ans,mx1+mx2);
    }
    // cerr<<"now ans="<<ans<<'\n';
    // 
    rep(i,1,n){
        int l=L[i],r=R[i];
        ll mx=0;
        rep(j,l+1,r-1)ckmax(mx,1ll*(a[j]-a[i])*(R[j]-L[j]-1));
        ckmax(ans,1ll*(r-l-1)*a[i]+mx);
    }
    // cerr<<"now ans="<<ans<<'\n';
    // 
    rep(i,1,n){
        static pll z1[N],z2[N];
        int l1=0,l2=0;
        for(ll j=L[i],now=a[i];j>=1;j--)ckmin(now,a[j]),z1[++l1]={now,R[i]-j};
        for(ll j=R[i],now=a[i];j<=n;j++)ckmin(now,a[j]),z2[++l2]={now,j-L[i]};
        // 
        for(ll x=1,y=l2,cur=0;x<=l1;x++){
            while(y>=1&&z1[x].fir+z2[y].fir<=a[i])ckmax(cur,1ll*z2[y].fir*z2[y].sec),y--;
            ckmax(ans,cur+1ll*z1[x].fir*z1[x].sec);
        }
        // 
        for(ll x=1,y=l2;x<=l1;x++){
            while(y>=1&&z1[x].fir+z2[y].fir<=a[i])y--;
            if(y>=1)ckmax(ans,1ll*z1[x].fir*z1[x].sec+1ll*(a[i]-z1[x].fir)*z2[y].sec);
        }
        // 
        for(ll y=1,x=l1;y<=l2;y++){
            while(x>=1&&z1[x].fir+z2[y].fir<=a[i])x--;
            if(x>=1)ckmax(ans,1ll*z2[y].fir*z2[y].sec+1ll*(a[i]-z2[y].fir)*z1[x].sec);
        }
    }
    print(ans,'\n');
    return 0;
}