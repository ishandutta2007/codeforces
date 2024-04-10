#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[201000];
vector<int>G[31];
int st[201000], L[201000], R[201000], top;
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        for(j=0;j<=30;j++){
            if((w[i]>>j)&1){
                G[j].push_back(i);
            }
        }
    }
    w[0] = 2e9;
    for(i=n;i>=0;i--){
        while(top && w[st[top]] <= w[i]){
            L[st[top]] = i+1;
            top--;
        }
        st[++top] = i;
    }
    for(i=1;i<=n;i++){
        R[i] = n;
        for(j=0;j<=30;j++){
            if(((w[i]>>j)&1) || G[j].empty())continue;
            int t = lower_bound(G[j].begin(),G[j].end(), i) - G[j].begin();
            if(t!=0){
                L[i] = max(L[i], G[j][t-1] + 1);
            }
            if(t!=G[j].size()){
                R[i] = min(R[i], G[j][t] - 1);
            }
        }
    }
    long long s = 1ll*n*(n+1)/2;
    for(i=1;i<=n;i++){
        s -= 1ll*(R[i]-i+1)*(i-L[i]+1);
    }
    printf("%lld\n",s);
}