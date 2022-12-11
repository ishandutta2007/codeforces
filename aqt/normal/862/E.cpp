#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
long long arr[100005], brr[100005];
long long pre[100005];
vector<long long> v;

long long bsl(long long k){
    int l = 0, r = v.size()-1, ret = 0;
    while(l <= r){
        int mid = l+r>>1;
        if(v[mid] <= k){
            ret = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return v[ret];
}

long long bsu(long long k){
    int l = 0, r = v.size()-1, ret = r;
    while(l <= r){
        int mid = l+r>>1;
        if(v[mid] >= k){
            ret = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return v[ret];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Q;
    long long tot = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        if(!(i&1)){
            arr[i] = -arr[i];
        }
        tot += arr[i];
    }
    for(int i= 1; i<=M; i++){
        cin >> brr[i];
        if((i&1) == 0){
            brr[i] = -brr[i];
        }
        pre[i] = pre[i-1] + brr[i];
    }
    for(int i = N; i<=M; i++){
        if(((i-N)&1)){
            v.push_back(-(pre[i]-pre[i-N]));
        }
        else{
            v.push_back(pre[i]-pre[i-N]);
        }
    }
    sort(v.begin(), v.end());
    cout << min(abs(tot-bsl(tot)), abs(tot-bsu(tot))) << "\n";
    while(Q--){
        int l, r, v;
        cin >> l >> r >> v;
        if(l%2 == 1 && r%2 == 1){
            tot += v;
        }
        if(l%2 == 0 && r%2 == 0){
            tot -= v;
        }
        cout << min(abs(tot-bsl(tot)), abs(tot-bsu(tot))) << "\n";
    }
}