#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
inline int read(){
    int x=0;char ch=getchar();
    int f=0;
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}

int main(){
    int T=read();
    while(T--){
        int n=read();
        rep(i,1,n)printf("%d ",int(1e9)-n+i);
        puts("");
    }
}