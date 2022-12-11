#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[5005];

long long solve(int l, int r, long long h){
    if(r-l < 0){
        return 0;
    }
    int idx = 0;
    for(int i = l; i<=r; i++){
        idx = (arr[idx] > arr[i]) ? i : idx;
    }
    return min(r-l+1LL, solve(l, idx-1, arr[idx]) + solve(idx+1, r, arr[idx]) + arr[idx] - h);
}

int main(){
    cin >> N;
    arr[0] = LLONG_MAX;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    cout << solve(1, N, 0) << endl;
}