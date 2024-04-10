#include <cstdio>

int cnt[1001];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        if(cnt[i]&1) ans++;
    }
    printf("%d\n",n-ans/2);
}