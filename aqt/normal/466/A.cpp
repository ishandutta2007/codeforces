#include <bits/stdc++.h>

using namespace std;

int N, M, A, B;

int main(){
    cin >> N >> M >> A >> B;
    int ans = N*A;
    for(int i = 1; i<=1000; i++){
        ans = min(ans, max(N-M*i, 0)*A + i*B);
    }
    cout << ans << endl;
}