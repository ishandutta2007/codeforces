#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long ans = 0;
    int ones = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 1)
            ones++;
        else
            ans += ones;
    }
    cout << ans << '\n';
    return 0;
}