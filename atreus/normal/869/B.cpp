#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    long long a, b;
    cin >> a >> b;
    if (b - a >= 5){
        cout << 0;
        return 0;
    }
    int ans = 1;
    for (long long i = a + 1; i <= b; i++){
        int k = i % 10;
        ans *= k;
    }
    cout << ans % 10 << endl;
}