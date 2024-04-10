// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
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

const int N=1000005;

int p[N];bool vis[N];
vector<int>cir;
int n,k;

int solve1(int k){ //  k k+1
    bitset<N> dp;
    dp.set(0);
    for(int i=0;i<SZ(cir);i++){
        int j=i;
        while(j+1<SZ(cir)&&cir[j+1]==cir[j])j++;
        int len=j-i+1;
        for(int k=1;k<=len;k<<=1){
            dp|=dp<<k*cir[i];
            len-=k;
        }
        if(len)dp|=dp<<len*cir[i];
        i=j;
    }
    if(dp.test(k))return k;
    else return k+1;
}
int solve2(int k){
    int ans=0,odd=0;
    for(auto &it:cir){
        int carry=min(k,it/2);
        k-=carry,ans+=2*carry;
        if(it&1)odd++;
    }
    if(k)ans+=min(odd,k);
    return ans;
}

int main(){
    n=read(),k=read();
    rep(i,1,n)p[i]=read();
    rep(i,1,n)if(!vis[i]){
        int k1=i,len=0;
        while(!vis[k1])vis[k1]=1,len++,k1=p[k1];
        cir.pb(len);
    }    
    sort(cir.begin(),cir.end());
    printf("%d %d\n",solve1(k),solve2(k));
    return 0;
}