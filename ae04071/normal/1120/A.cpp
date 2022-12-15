#include <bits/stdc++.h>
using namespace std;

int n,k,m,s;
int arr[500100],cnt[500100];

int main() {
    scanf("%d%d%d%d",&n,&k,&m,&s);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    for(int i=0;i<s;i++) {
        int v;
        scanf("%d",&v);
        cnt[v]++;
    }

    int rem=0;
    for(int i=1;i<=500000;i++) if(cnt[i]) rem++;
    for(int i=0,j=0;j<n;j++) {
        cnt[arr[j]]--;
        if(cnt[arr[j]]==0) rem--;

        while(!rem && j-i+1>=k) {
            if(i/k + (n-j-1)/k + 1 >= m) {
                printf("%d\n",max((j-i+1)-k,0) + (i)%k);
                for(int t=0;t<(i)%k;t++) printf("%d ",t+1);
                
                int cc=max(j-i+1-k,0);
                for(int t=i;t<=j;t++) {
                    if(cc && cnt[arr[t]]+1<=0) {
                        cc--;
                        cnt[arr[t]]++;
                        printf("%d ",t+1);
                    }
                }
                return 0;
            }
            cnt[arr[i]]++;
            if(cnt[arr[i]]==1) rem++;
            i++;
        }
    }
    puts("-1");
    
    return 0;
}