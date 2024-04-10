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

int n,m,rb,cb,rd,cd;

void solve(){
    n=read(),m=read(),rb=read(),cb=read(),rd=read(),cd=read();
    if(rb==rd||cb==cd){
        puts("0");
        return;
    } 
    int dirx=1,diry=1,times=0;
    while(1){
        if(dirx==1&&rb==n)dirx=-1;
        if(dirx==-1&&rb==1)dirx=1;
        if(diry==1&&cb==m)diry=-1;
        if(diry==-1&&cb==1)diry=1;
        rb+=dirx;cb+=diry;
        ++times;
        if(rb==rd||cb==cd){
            print(times,'\n');
            return;
        }
    }    
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}