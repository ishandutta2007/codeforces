#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,k;
pii arr[100001];
long long ans[100001];

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d%d",&arr[i].first,&arr[i].second);

    sort(arr,arr+n);

    int x=0;
    multiset<pii> tr;
    for(int i=0,j=0;i<n;) {
        if(i==j) x = arr[i].first-k+1;
        else x++;

        for(;j<n && arr[j].first-k+1<=x; j++) {
            tr.insert({arr[j].second-k+1, 1});
            tr.insert({arr[j].second+1, -1});
        }

        int px = tr.begin()->first, cnt=0;
        for(auto &it:tr) {
            ans[cnt] += it.first - px;
            px = it.first;
            cnt += it.second;
        }

        for(;i<n && arr[i].first<=x; i++) {
            tr.erase(tr.lower_bound({arr[i].second-k+1, 1}));
            tr.erase(tr.lower_bound({arr[i].second+1, -1}));
        }
    }
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    
    return 0;
}