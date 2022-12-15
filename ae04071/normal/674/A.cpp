#include <bits/stdc++.h>
using namespace std;

int cnt[5001],n,arr[5001],ans[5001];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    for(int i=0;i<n;i++) {
        int mx=0,mc=0;
        memset(cnt,0,sizeof(cnt));
        for(int j=i;j<n;j++) {
            cnt[arr[j]]++;
            if(cnt[arr[j]] > mx || (mx==cnt[arr[j]] && arr[j] < mc)) {
                mx=cnt[arr[j]];
                mc=arr[j];
            }
            ans[mc]++;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    
    return 0;
}