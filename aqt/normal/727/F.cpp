#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[755];
long long ans[755];

int chk(long long v){
    priority_queue<int, vector<int>, greater<int>> pq;
    int ret = 0;
    for(int i = 1; i<=N; i++){
        pq.push(arr[i]);
        v += arr[i];
        while(v < 0){
            v -= pq.top();
            pq.pop();
            ret++;
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    int L = chk(0);
    for(int k = 0; k<=L; k++){
        long long l = 1, r = 1000000000000000;
        ans[k] = LLONG_MAX;
        while(l <= r){
            long long mid = l+r>>1;
            if(chk(mid) <= k){
                ans[k] = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    }
    while(Q--){
        long long n;
        cin >> n;
        int out = L;
        for(int k = 0; k<=L; k++){
            if(ans[k] <= n){
                out = min(out, k);
            }
        }
        cout << out << "\n";
    }
}