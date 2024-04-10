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
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char let){
    print(x),putchar(let);
}

const int N=100005;

int arr[N];

int main(){
    int T=read();
    while(T--){
        int n=read(),a=read(),b=read();
        if(a+b>n-2||abs(a-b)>1){
            puts("-1");
            continue;
        }
        if(a==b){
            for(int i=1;i<=n;i++)arr[i]=i;
            for(int i=2,j=1;j<=a;j++,i+=2)swap(arr[i],arr[i+1]);
            for(int i=1;i<=n;i++)printf("%d ",arr[i]);
            puts("");
        }else if(a>b){
            for(int i=1;i<=n;i++)arr[i]=i;
            for(int i=n,j=1;j<=a;j++,i-=2)swap(arr[i],arr[i-1]);
            for(int i=1;i<=n;i++)printf("%d ",arr[i]);
            puts("");
        }else{
            for(int i=1;i<=n;i++)arr[i]=n+1-i;
            for(int i=n,j=1;j<=b;j++,i-=2)swap(arr[i],arr[i-1]);
            for(int i=1;i<=n;i++)printf("%d ",arr[i]);
            puts("");
        }
    }
    return 0;
}