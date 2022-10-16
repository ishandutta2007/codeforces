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

char a[100005];
int n;

void solve(){
    scanf("%d",&n);
    scanf("%s",a+1);
    if(n>1&&a[1]==a[2]){
        printf("%c%c\n",a[1],a[2]);
    }else{
        rep(i,1,n-1){
            if(a[i]<a[i+1]){
                rep(j,1,i)printf("%c",a[j]);
                per(j,i,1)printf("%c",a[j]);
                puts("");
                return;
            }
        }
        rep(i,1,n)printf("%c",a[i]);
        per(i,n,1)printf("%c",a[i]);
        puts("");
    }
}
int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}