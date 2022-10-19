#include <cstdio>
#include <algorithm>

#define M 100100

using namespace std;

int a[M],s[M],t[M],n,d[M];

void read(void){
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    scanf("%d",&a[i]);

    for (int i=1; i<=n; ++i)
    s[i]=s[i-1]+a[i];
    for (int i=n; i>=1; --i)
    t[i]=t[i+1]+a[i];
}

void din(void){
    for (int i=n; i>=1; --i)
    d[i]=max((a[i]+d[i+1]),(-t[i]));
}

void calc(void){
    int ans=s[n];
    for (int i=0; i<=n; ++i)
    ans=max(ans,(-s[i]+d[i+1]));
    printf("%d\n",ans);
}

int main()
{
    read();
    din();
    calc();
    return 0;
}