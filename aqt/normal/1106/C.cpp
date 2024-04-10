#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[300005];

int main(){
    scanf("%d", &N);
    for(int i = 1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr+1, arr+1+N);
    long long ans = 0;
    for(int i = 1; i<=N/2; i++){
        ans += (arr[i] + arr[N-i+1])*(arr[i] + arr[N-i+1]);
    }
    cout << ans <<endl;
}