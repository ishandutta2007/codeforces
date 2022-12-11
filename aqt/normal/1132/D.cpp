#include <bits/stdc++.h>

using namespace std;

int N, K;
long long arr[200005], brr[200005];

struct comp{
    long long init, lose, val;
    bool operator < (comp c) const{
        return c.val < val;
    }
};
bool solve(long long x){
    priority_queue<comp> pq;
    for(int i = 1; i<=N; i++){
        pq.push({arr[i], brr[i], arr[i]/brr[i]});
    }
    for(long long t = 0; t<K; t++){
        if(pq.top().init < pq.top().lose*t){
            return 0;
        }
        comp c = pq.top();
        pq.pop();
        c.init += x;
        c.val = c.init/c.lose;
        pq.push(c);
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=1 ; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> brr[i];
    }
    long long l = 0, r = 10000000000000LL;
    long long ans = -1;
    while(l <= r){
        long long mid = l+r>>1LL;
        if(solve(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}