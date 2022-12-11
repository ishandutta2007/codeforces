#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int B, P, C;
        cin >> B >> P >> C;
        int PC, CC;
        cin >> PC >> CC;
        int ans = 0;
        for(int i = 0; i<=P; i++){
            for(int j = 0; j<=C; j++){
                if((i+j)*2 <= B){
                    ans = max(ans, PC*i+CC*j);
                }
            }
        }
        cout << ans << "\n";
    }
}