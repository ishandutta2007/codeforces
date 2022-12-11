#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, a, b, c;
    int ans = 0;
    cin >> N >> a >> b >> c;
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            if((N-i*a-j*b) >= 0 && (N-i*a-j*b)%c == 0){
                ans = max(ans, (N-i*a-j*b)/c + i + j);
            }
        }
    }
    cout << ans << endl;
}