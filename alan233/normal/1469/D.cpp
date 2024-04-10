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

vector<pii>ans;
int n;

void solve(int n){
    if(n<=2)return;
    int B=ceil(sqrt(n));
    for(int i=B+1;i<n;i++)ans.pb({i,n});
    ans.pb({n,B}),ans.pb({n,B});
    solve(B);
}

int main(){
    int T=read();
    while(T--){
        n=read();
        ans.clear();
        solve(n);
        printf("%d\n",SZ(ans));for(auto v:ans)printf("%d %d\n",v.fir,v.sec);           
    }
}