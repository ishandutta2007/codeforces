#include <cstdio>

#define reg register
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

int a[110];

int main() {
    int t=R();
    while(t--) {
        int n=R(),l=1,r=10000000,ans=0;ll f=0;
        for(int i=1;i<=n;i++) fr(a[i]),f+=a[i];
        while(l<=r) {
            int mid=(l+r)/2;
            if(mid*n>=f)ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//Naive_Cat