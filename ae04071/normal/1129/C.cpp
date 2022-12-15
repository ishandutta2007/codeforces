#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii = pair<int,int>;
using lli = long long ;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

const int MOD=1e9+7;
int dp[3001][4][1<<3],n,a[3001];
int ext[5][1<<4],gi;

vector<vector<int>> arr;

int ans[3001][3001],lcp[3001][3001];

int DP(int idx,int r,int s) {
    int &ret=dp[idx][r][s];
    if(ret!=-1) return ret;

    if(idx==0) return ret = (r==0 && s==0);
    
    ret=0;
    if(r==4) return ret = 0;
    
    int ns = s<<1 | arr[gi][idx];
    if(!ext[r+1][ns]) ret = (ret + DP(idx-1,0,0))%MOD;
    if(r!=3) ret = (ret + DP(idx-1,r+1,ns))%MOD;
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) {
        arr.push_back(vector<int>(1,0));
        for(int j=i;j<=n;j++) arr.back().push_back(a[j]);
    }
    sort(arr.begin(),arr.end());
    ext[4][12]=ext[4][10]=ext[4][7]=ext[4][15]=1;
    memset(dp,-1,sizeof(dp));

    for(int i=1;i<n;i++) {
        int j=0;
        for(j=1;j<min(sz(arr[i-1]), sz(arr[i])) && arr[i-1][j]==arr[i][j];j++);
        lcp[i-1][i] = j-1;
    }
    for(int i=1;i<n;i++) {
        for(int j=i-2;j>=0;j--) {
            lcp[j][i] = min(lcp[j][j+1],lcp[j+1][i]);
        }
    }
    
    gi = 0;
    int s= n - sz(arr[0])+2;
    for(int i=1;i<sz(arr[0]);i++) {
        ans[s][s+i-1] = DP(i,0,0);
    }
    stack<int> stk;
    stk.push(0);
    for(int i=1;i<n;i++) {
        int j=lcp[i-1][i]+1;
        for(int k=j;k<sz(arr[i]);k++) for(int a=0;a<4;a++) for(int b=0;b<8;b++)
            dp[k][a][b] = -1;

        gi = i;
        s = n-sz(arr[i])+2;
        for(int k=j;k<sz(arr[i]);k++) {
            ans[s][s+k-1] = DP(k,0,0);  
        }
        while(!stk.empty() && sz(arr[stk.top()]) < sz(arr[i])) {
            int ps = n-sz(arr[stk.top()])+2, l=lcp[stk.top()][i]; stk.pop();
            for(int k=1;k<=l;k++) {
                ans[s][s+k-1] = (ans[s][s+k-1] + ans[ps][ps+k-1])%MOD;
                ans[ps][ps+k-1] = 0;
            }
        }
        stk.push(i);
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[i][j] = ((1ll*ans[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1])%MOD+MOD)%MOD;
    
    for(int i=1;i<=n;i++) printf("%d\n",ans[i][i]);
    
    return 0;
}