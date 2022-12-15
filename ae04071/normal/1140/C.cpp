#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using lli = long long;

int n,k;
pii arr[300000];

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+n,[](const pii &a,const pii &b) {
            return a.second > b.second;
    });

    priority_queue<int,vector<int>,greater<int>> que;
    lli sum=0,ans=0;
    for(int i=0;i<n;i++) {
        que.push(arr[i].first);
        sum += arr[i].first;
        while(que.size() > k) {
            sum -= que.top(); que.pop();
        }
        ans = max(ans, sum*arr[i].second);

    }
    printf("%lld\n",ans);
    
    return 0;
}