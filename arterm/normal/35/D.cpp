#include <cstdio>
#include <algorithm>

#define M 121

using namespace std;

int n,x,a[M];

void read(void){
    scanf("%d%d",&n,&x);
    for (int i=0,y; i<n; ++i){
        scanf("%d",&y);
        a[i]=(n-i)*y;
    }
    sort(a,a+n);
}

void kill(void){
    int ans=0,t=0;
    while (t<n && x>=a[t]){
        ans++;
        x-=a[t];
        t++;
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    kill();
    return 0;
}