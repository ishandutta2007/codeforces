#include <bits/stdc++.h>

using namespace std;

long long arr[100005];
long long pre[100005];
long long dif[100005];

int main(){
    int N;
    cin >> N;
    long long maxi = 0, mini = LLONG_MAX;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    for(int i= 1; i<N; i++){
        dif[i] = arr[i+1]-arr[i];
    }
    sort(dif+1, dif+N);
    for(int i = 1; i<N; i++){
        pre[i] = dif[i] + pre[i-1];
    }
    int Q;
    cin >> Q;
    while(Q--){
        long long l, r;
        cin >> l >> r;
        long long d = r-l+1;
        int idx = upper_bound(dif+1, dif+N, d) - dif-1;
        cout << d*(N-idx)+pre[idx] << " ";
    }
}