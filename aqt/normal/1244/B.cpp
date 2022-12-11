#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int N;
        string s;
        cin >> N >> s;
        int ans = N;
        for(int i = 0; i<N; i++){
            if(s[i] == '1'){
                ans = max(ans, 2*max(N-i, i+1));
            }
        }
        cout << ans << "\n";
    }
}