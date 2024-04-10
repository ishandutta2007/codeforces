#include <cstdio>

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

const int N=2e3;
int a[N+10][N+10],sum[N+10][N+10],f[N+10][N+10];
char str[N+10];

template<class T>T cmin(T a,T b) {return a<b?a:b;}
template<class T>T cmax(T a,T b) {return a>b?a:b;}

int main() {
    int n=R(),k=R(),ans=0,Max=0,cnt=0,l=n+1,r=0;
    for(int i=1;i<=n;i++) {
        scanf("%s",str+1);
        for(int j=1;j<=n;j++) a[i][j]=(str[j]=='B');
    }
    for(int i=1;i<=n;i++,cnt=r=0,l=n+1) {
        for(int j=1;j<=n;j++) if(a[i][j])l=cmin(l,j),r=cmax(r,j),cnt++;
        if(cnt==0)ans++;
        else if(r-l>=k)continue;
        else {
            int x=cmax(1,r-k+1);
            sum[i][l]++,sum[i][x-1]--;
            if(i>=k)sum[i-k][l]--,sum[i-k][x-1]++;
        }
    }
    cnt=r=0,l=n+1;
    for(int i=1;i<=n;i++,cnt=r=0,l=n+1) {
        for(int j=1;j<=n;j++) if(a[j][i])l=cmin(l,j),r=cmax(r,j),cnt++;
        if(cnt==0)ans++;
        else if(r-l>=k)continue;
        else {
            int x=cmax(1,r-k+1);
            sum[l][i]++,sum[x-1][i]--;
            if(i>=k)sum[l][i-k]--,sum[x-1][i-k]++;
        }
    }
    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--)
            f[i][j]=f[i+1][j]+f[i][j+1]-f[i+1][j+1]+sum[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) Max=cmax(Max,f[i][j]);
    return !printf("%d\n",ans+Max);
}