#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        ans = max(ans, n);
    }
    cout << ans << endl;
}