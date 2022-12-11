#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    int ans = 40;
    for(int i = 0; i<ans && N > 0; i++){
        if(__builtin_popcount(N) <= i && N >= i){
            ans = min(ans, i);
        }
        N -= M;
    }
    if(ans == 40){
        ans = -1;
    }
    cout << ans << endl;
}