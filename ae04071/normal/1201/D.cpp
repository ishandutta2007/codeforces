#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n,m,k,q;
pair<int,int> arr[200011];
int col[200001];

int main() {
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=0;i<k;i++) scanf("%d%d",&arr[i].fi,&arr[i].se);
    for(int i=0;i<q;i++) scanf("%d",col+i);
    arr[k++] = pair<int,int>(1, 1);
    sort(arr,arr+k);
    sort(col,col+q);

    long long ans=1e15,s=arr[0].fi - 1;
    vector<pair<int,long long>> cand;
    cand.push_back({1, 0});
    for(int i=0,j=0;i<k;i=j){
        for(j=i;j<k && arr[i].first==arr[j].first;j++);
        
        vector<pair<int, long long>> next;
        int idx = lower_bound(col,col+q,arr[i].second)-col;
        if(idx!=q) next.push_back({col[idx], 1e15});
        if(idx!=0) next.push_back({col[--idx], 1e15});
        
        idx = lower_bound(col,col+q, arr[j-1].se)-col;
        if(idx!=q) next.push_back({col[idx], 1e15});
        if(idx!=0) next.push_back({col[--idx], 1e15});

        sort(next.begin(),next.end());
        next.erase(unique(next.begin(),next.end()),next.end());
        for(auto &v:cand) {
            // L -> R
            int dist = abs(v.fi-arr[i].se) + arr[j-1].se-arr[i].se;
            if(j==k) {
                ans = min(ans, v.se + dist);
            } else {
                for(auto &t:next) {
                    t.se = min(t.se, v.se+dist+abs(t.fi-arr[j-1].se));
                }
            }

            dist = abs(v.fi-arr[j-1].se) + arr[j-1].se-arr[i].se;
            if(j==k) {
                ans = min(ans, v.se + dist);
            } else {
                for(auto &t:next) {
                    t.se = min(t.se, v.se+dist+abs(t.fi-arr[i].se));
                }
            }
        }
        cand = next;
        if(j!=k) s += arr[j].fi-arr[i].fi;
    }
    printf("%lld\n",ans + s);
    
    return 0;
}