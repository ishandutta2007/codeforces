#include <iostream>

using namespace std;

int getD(int n) {
    n--;
    if(n == 0)
        return 1;
    int res = 0;
    while(n) {
        n /= 7;
        res++;
    }
    return res;
}

char used[7];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int dn = getD(n), dm = getD(m);
    if(dn + dm > 7) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 7; k++)
                used[k] = false;
            int x = i;
            bool ok = true;
            for(int k = 0; k < dn; k++) {
                int d = x % 7;
                x /= 7;
                if(used[d])
                    ok = false;
                used[d] = true;
            }
            x = j;
            for(int k = 0; k < dm; k++) {
                int d = x % 7;
                x /= 7;
                if(used[d])
                    ok = false;
                used[d] = true;
            }
            if(ok)
                ans++;
        }
    cout << ans << '\n';
    return 0;
}