#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 0;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        int mini = 1, maxi = INT_MAX;
        for(int i= 1; i<=N; i++){
            int n;
            cin >> n;
            mini = max(mini, n-K);
            maxi = min(maxi, n+K);
        }
        if(mini > maxi){
            cout << -1 << endl;
        }
        else{
            cout << maxi << endl;
        }
    }
}