#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int,int>;

int d,n,m;
pii arr[200002];

int main() {
    scanf("%d%d%d",&d,&n,&m);
    for(int i=0;i<m;i++) scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+m);
    arr[m].first=d;

    int cd=0;
    lli ans=0;
    deque<pii> que;
    que.push_back({n,m+1});
    for(int i=0;i<=m;i++) {
        while(!que.empty() && cd<arr[i].first) {
            ans += 1ll*(min(arr[i].first,que.front().first)-cd)*arr[que.front().second].second;
            cd = min(arr[i].first, que.front().first);
            if(cd<arr[i].first) que.pop_front();
        }
        if(que.empty()) {
            puts("-1");
            return 0;
        }
        while(!que.empty() && arr[que.back().second].second >= arr[i].second)
            que.pop_back();
        que.push_back({arr[i].first+n,i});
    }
    printf("%lld\n",ans);

    return 0;
}