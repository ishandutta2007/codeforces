#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,m,dp[50][50][51],vis[50][50][51];
int L[50],R[50],H[50],V[50];
vector<pii> arr;
int DP(int l,int r,int h) {
    if(l>r || h==0) return 0;

    int &ret=dp[l][r][h];
    if(ret!=-1) return ret;
    
    ret=DP(l,r,h-1);
    int j=0,ad=0;
    for(int i=l;i<=r;i++) {
        while(j<m*2 && arr[j].first<=i) {
            if(L[arr[j].second]<l || R[arr[j].second]>r) {
                j++; continue;
            }

            if(L[arr[j].second]==arr[j].first) {
                ad -= h>=H[arr[j].second] ? V[arr[j].second] : 0;
            } else if(L[arr[j].second]>=l) {
                ad += h>=H[arr[j].second] ? V[arr[j].second] : 0;
            }
            j++;
        }
        ret = max(ret, DP(l,i-1,h) + DP(i+1,r,h) + h*h + ad);
    }
    return ret;
}
int main() {
    int h;
    scanf("%d%d%d",&n,&h,&m);
    for(int i=0;i<m;i++) scanf("%d%d%d%d",L+i,R+i,H+i,V+i);
    for(int i=0;i<m;i++) L[i]--,R[i]--,H[i]++;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++) arr.push_back(pii(L[i],i)),arr.push_back(pii(R[i]+1,i));
    sort(arr.begin(),arr.end());
    printf("%d\n",DP(0,n-1,h));

    return 0;
}