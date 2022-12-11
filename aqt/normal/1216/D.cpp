#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N, greater<int>());
    int gcd = 0;
    for(int i = 1; i<=N; i++){
        arr[i] -= arr[N];
        gcd = __gcd(gcd, arr[i]);
    }
    if(gcd == 0){
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    long long cnt = 0;
    for(int i = 1; i<=N; i++){
        cnt += (arr[1]-arr[i])/gcd;
    }
    cout << cnt << " " << gcd << endl;
}