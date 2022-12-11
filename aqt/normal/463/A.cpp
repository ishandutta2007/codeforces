#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    K*=100;
    int ans = -1;
    for(int i = 1; i<=N; i++){
        int p, c;
        cin >> p >> c;
        if(K >= p*100+c){
            ans = max(ans, (100-c)%100);
        }
    }
    cout << ans << endl;
}