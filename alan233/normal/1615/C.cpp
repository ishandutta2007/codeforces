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
#define poly vector<int>
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

const int N=200005;

char a[N],b[N];
int n;

void solve(){
    scanf("%d%s%s",&n,a+1,b+1);
    rep(i,1,n)a[i]-='0',b[i]-='0';
    
    int ans=1e9;
    // 
    {
        int times=0,t=0;
        rep(i,1,n){
            if(a[i]!=b[i])times++,t+=a[i]?1:-1; 
        }
        if(times%2==0&&!t){
            ckmin(ans,times);
        }
    }
    // 
    {
        int times=0,t=0;
        rep(i,1,n){
            if(a[i]==b[i])times++,t+=a[i]?1:-1;
        }
        if(times%2==1&&t==1){
            ckmin(ans,times);
        }
    } 
    if(ans==1e9)puts("-1");
    else printf("%d\n",ans);
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}