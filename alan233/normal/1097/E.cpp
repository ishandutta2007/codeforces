// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
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

const int N=100005;

vector<int>ans[N];int tot;
int n;

struct Bit{
    pii c[N];
    void init(int n){
        rep(i,1,n)c[i]={0,-1};
    }
    void ins(int x,pii dlt){
        while(x<=n){
            ckmax(c[x],dlt);
            x+=x&-x;
        }
    }
    pii qry(int x){
        pii ret={0,-1};
        while(x>0){
            ckmax(ret,c[x]);
            x^=x&-x;
        }
        return ret;
    }
    void clr(int x){
        while(x<=n){
            c[x]={0,-1};
            x+=x&-x;
        }
    }
}tr;

inline int calc(int n){
    int l=0,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(1ll*mid*mid+mid<=2*n)l=mid;
        else r=mid-1;
    }
    return l;
}

vector<int>new_a;
vector<int>dp,from;
vector<int>tag;
set<pii>s;

void sol(vector<int>a){
    int n=SZ(a);
    if(!n)return;
    dp.resize(n),from.assign(n,-1);
    int mx=-1,who=0;
    for(int i=0;i<n;i++){
        pii it=tr.qry(a[i]);
        dp[i]=it.fir+1,from[i]=it.sec;
        tr.ins(a[i],{dp[i],i});
        if(dp[i]>mx)mx=dp[i],who=i;
    }
    for(int i=0;i<n;i++)tr.clr(a[i]);
/*  
    printf("now sol: ");for(auto it:a)printf("%d ",it);puts("");
    printf("mx=%d,who=%d\n",mx,who);
    printf("calc=%d\n",calc(n));
*/
    if(mx<=calc(n)){
        s.clear();
        for(auto i:a){
            auto it=s.lower_bound({i,-1});
            if(it==s.end()){
                ++tot;
                ans[tot].pb(i);
                s.insert({i,tot});
            }else{
                int group=it->sec;
                s.erase(it);
                ans[group].pb(i);
                s.insert({i,group});
            }
        }
    }else{
        ++tot;
        for(;who!=-1;who=from[who]){
            ans[tot].pb(a[who]);
            tag[a[who]]=1;
        }
        reverse(ans[tot].begin(),ans[tot].end());
        
        new_a.clear();
        for(int i=0;i<n;i++){
            if(!tag[a[i]]){
                new_a.pb(a[i]);
            }
        }
        for(int i=0;i<n;i++)tag[a[i]]=0;
        sol(new_a);
    }
}

void solve(){
    while(tot){
        ans[tot].clear(),ans[tot].shrink_to_fit();
        tot--;
    }
    
    n=read();tr.init(n),tag.resize(n+1);
    vector<int>a(n);
    for(auto &it:a)it=read();
    sol(a);
    printf("%d\n",tot);
    rep(i,1,tot){
        printf("%d ",SZ(ans[i]));
        for(auto it:ans[i])printf("%d ",it);
        puts("");
    }
}

int main(){
    int T=read();
    while(T--)solve();
    return 0; 
}