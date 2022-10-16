#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int p, k;
    cin >> p >> k;
    if(k == 0) {
        int ans = 1;
        for(int i = 1; i < p; i++)
            ans = (long long)ans * p % MOD;
        cout << ans << '\n';
        return 0;
    }
    if(k == 1) {
        int ans = 1;
        for(int i = 0; i < p; i++)
            ans = (long long)ans * p % MOD;
        cout << ans << '\n';
        return 0;
    }
    int ans = 1;
    for(int i = 1; i < p; i++)
        if(!used[i]) {
            ans = (long long)ans * p % MOD;
            used[i] = true;
            int x = (long long)i * k % p;
            while(!used[x]) {
                used[x] = true;
                x = (long long)x * k % p;
            }
        }
    cout << ans << '\n';
    return 0;
}