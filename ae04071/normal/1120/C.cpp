#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

char str[5001];
vector<pair<string,int>> arr;
int lcp[5001],cs[5001][5001];
int dp[5001],n,a,b;

int DP(int idx) {
    if(idx==n) return 0;
    int &ret=dp[idx];
    if(ret!=-1) return ret;

    ret=DP(idx+1)+a;
    for(int i=0;i<idx;i++) ret = min(ret,DP(idx+cs[idx][i])+b);
    return ret;
}

int main() {
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",str);
    for(int i=0;i<n;i++) {
        string s(str+i,str+n);
        arr.push_back({s,i});
    }
    sort(arr.begin(),arr.end());

    for(int i=1;i<n;i++) {
        int j=0;
        for(;j<min(arr[i-1].first.size(), arr[i].first.size());j++) {
            if(arr[i-1].first[j]!=arr[i].first[j]) break;
        }
        lcp[i]=j;
    }

    for(int i=0;i<n;i++) {
        int l=lcp[i];
        for(int j=i-1;j>=0;j--) {
            if(arr[j].second < arr[i].second) {
                cs[arr[i].second][arr[j].second] = min(arr[i].second-arr[j].second,l);
            }
            l=min(l,lcp[j]);
        }
        l=lcp[i+1];
        for(int j=i+1;j<n;j++) {
            if(arr[j].second < arr[i].second) {
                cs[arr[i].second][arr[j].second] = min(arr[i].second-arr[j].second,l);
            }
            l=min(l,lcp[j+1]);
        }
    }

    memset(dp,-1,sizeof(dp));
    printf("%d\n",DP(0));

    return 0;
}