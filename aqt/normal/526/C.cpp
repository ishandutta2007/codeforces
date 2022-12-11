#include <bits/stdc++.h>

using namespace std;

long long K, V1, V2, W1, W2;

int main(){
    cin >> K >> V1 >> V2 >> W1 >> W2;
    if(W1 < W2){
        swap(V1, V2);
        swap(W1, W2);
    }
    long long ans = 0;
    if(sqrt(K) <= W1){
        for(long long i = 0; i*W1 <= K; i++){
            ans = max(ans, i*V1 + (K-i*W1)/W2*V2);
        }
    }
    else{
        for(long long i = 0; i <= W2; i++){
            ans = max(ans, i*V1 + (K-i*W1)/W2*V2);
        }
        for(long long i = 0; i <= W1; i++){
            ans = max(ans, i*V2 + (K-i*W2)/W1*V1);
        }
    }
    cout << ans << endl;
}