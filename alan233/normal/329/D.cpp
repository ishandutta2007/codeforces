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

char a[105][105];

void make(){
    int n=100;
    rep(i,1,n)rep(j,1,n)a[i][j]='.';
    int B=50;
    
    for(int i=1;i<=B;i++)a[i][1]='v';
    for(int i=B+2;i<n;i+=2)a[i][1]='v';
    
    for(int i=2;i<=n;i++)a[1][i]='<';
    for(int i=2;i<=n;i++)a[i][n]='^';
    
    a[n][1]='>';
    
    for(int j=2;j<n;j++){
        if(j%2==0){
            for(int i=n;i>=n-B+1;i--)a[i][j]='^';
            for(int i=n-B-1;i>=3;i-=2)a[i][j]='^';
            a[2][j]='>';
        }else{
            for(int i=2;i<=B+1;i++)a[i][j]='v';
            for(int i=B+3;i<n;i+=2)a[i][j]='v';
            a[n][j]='>';
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",a[i][j]);
        }
        puts("");
    }
    puts("1 1");
}

int main(){
//    freopen("data.out","w",stdout);
    int n=read(),x=read();
    if(n==5){
        printf(R"(>...v
v.<..
..^..
>....
..^.<
1 1
        )");
        return 0;
    }
    if(n==3){
        printf(R"(>vv
^<.
^.<
1 3
        )");
        return 0;
    }
    make();
    
    
}