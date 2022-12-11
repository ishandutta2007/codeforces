#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int N, M, K;
        cin >> N >> M >> K;
        int pre;
        bool ans = 1;
        cin >> pre;
        for(int i = 2; i<=N; i++){
            int n;
            cin >> n;
            int delta = max(0, n-K)-pre;
            if(M-delta < 0){
                ans = 0;
            }
            M -= delta;
            pre = n;
        }
        if(ans){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}