#include <bits/stdc++.h>

using namespace std;

long long x[1000005], y[1000005], v[1000005], dp[1000005];
int N;
priority_queue<pair<long long, int>> pq;
deque<int> ll;

double slope(int j, int k){
    return (dp[k]-dp[j])/(1.0*x[k]-x[j]);
}

int main(){
    scanf("%d", &N);
    for(int i =1; i<=N; i++){
        scanf("%lld %lld %lld", &x[i], &y[i], &v[i]);
        pq.push({-x[i], i});
    }
    ll.push_back(0);
    while(!pq.empty()){
        int idx = pq.top().second;
        pq.pop();
        while(ll.size() >= 2){
            int idx1 = ll.front();
            ll.pop_front();
            int idx2 = ll.front();
            ll.pop_front();
            if(slope(idx1, idx2) >= y[idx]){
                ll.push_front(idx2);
            }
            else{
                ll.push_front(idx2);
                ll.push_front(idx1);
                break;
            }
        }
        dp[idx] = dp[ll.front()] + (x[idx]-x[ll.front()])*y[idx] - v[idx];
        while(ll.size() >= 2){
            int idx1 = ll.back();
            ll.pop_back();
            int idx2 = ll.back();
            ll.pop_back();
            if(slope(idx2, idx1) <= slope(idx1, idx)){
                ll.push_back(idx2);
            }
            else{
                ll.push_back(idx2);
                ll.push_back(idx1);
                break;
            }
        }
        ll.push_back(idx);
    }
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}