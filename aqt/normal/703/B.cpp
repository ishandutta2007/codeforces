#include <bits/stdc++.h>

using namespace std;

int N, K;
long long arr[100005];
bool cap[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    long long sum = 0;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    for(int k = 0; k<K; k++){
        int n;
        cin >> n;
        n--;
        cap[n] = 1;
    }
    long long ans = 0;
    for(int i = 0; i<N; i++){
        if(cap[i]){
            continue;
        }
        if(!cap[(i+1)%N]){
            ans += arr[(i+1)%N] * arr[i];
        }
    }
    for(int k = 0; k<N; k++){
        if(cap[k]){
            sum -= arr[k];
            ans += (sum)*arr[k];
        }
    }
    cout << ans << endl;
}