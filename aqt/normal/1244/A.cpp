#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        pair<int, int> ans = {-1, 0};
        for(int i = 0; i<=k; i++){
            for(int j = 0; j<=k-i; j++){
                if(i*c >= a && d*j >= b){
                    ans.first = i;
                    ans.second = j;
                }
            }
        }
        if(ans.first == -1){
            cout << -1 << "\n";
        }
        else{
            cout << ans.first << " " << ans.second << "\n";
        }
    }
}