#include <bits/stdc++.h>

using namespace std;
int arr[101];

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int k = 0; k<K; k++){
        int s = 0;
        for(int i = 0; i<N; i++){
            if(((i-k)%K))
            s += arr[i];
        }
        ans = max(ans, abs(s));
    }
    cout << ans << endl;
}