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

const int N=200005;

char a[N];
int n;

void solve(){
    scanf("%s",a+1);
    n=strlen(a+1);
    for(int i=n-1;i>=1;i--){
        if(a[i]+a[i+1]-2*'0'>=10){
            for(int j=1;j<i;j++)printf("%c",a[j]);
            printf("%d",a[i]+a[i+1]-2*'0');
            for(int j=i+2;j<=n;j++)printf("%c",a[j]);
            puts("");
            return;
        }
    }    
    printf("%c",a[1]+a[2]-'0');
    for(int j=3;j<=n;j++)printf("%c",a[j]);
    puts("");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}