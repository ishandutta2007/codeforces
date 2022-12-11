#include <bits/stdc++.h>

using namespace std;

int N, K, M;
int arr[100005];

int main(){
    cin >> N >> K >> M;
    long long tot = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        tot += arr[i];
    }
    sort(arr+1, arr+1+N);
    double ans = 0;
    for(int i = 0; i<=min(M, N-1); i++){
        tot -= arr[i];
        ans = max(ans, 1.0*tot/(N-i)+1.0*(min(1.0*M-1.0*i, 1.0*K*(N-i))/(N-i)));
    }
    printf("%.13f", ans);
}