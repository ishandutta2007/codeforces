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

int pre[20][200005];

void solve(){
    int l=read(),r=read(),ans=1e9;
    rep(i,0,19)ckmin(ans,pre[i][r]-pre[i][l-1]);
    print(ans,'\n');
}

int main(){
    rep(i,1,200000){
        rep(j,0,19)pre[j][i]=pre[j][i-1];
        rep(j,0,19){
            if(!(i>>j&1))pre[j][i]++;
        }
    }
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}