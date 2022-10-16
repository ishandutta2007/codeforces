#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 205;
int a[MAXN], lr[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = a[0];
    for(int l = 0; l < n; l++) {
        int sum = 0;
        for(int r = l; r < n; r++) {
            sum += a[r];
            int m = 0;
            for(int i = l; i <= r; i++) {
                lr[m] = a[i];
                m++;
            }
            int m1 = 0;
            for(int i = 0; i < l; i++) {
                b[m1] = a[i];
                m1++;
            }
            for(int i = r + 1; i < n; i++) {
                b[m1] = a[i];
                m1++;
            }
            sort(lr, lr + m);
            sort(b, b + m1);
            int q = min(k, min(m, m1)), s = sum;
            for(int i = 0; i < q; i++)
                if(b[m1 - i - 1] > lr[i])
                    s += b[m1 - i - 1] - lr[i];
                else
                    break;
            ans = max(ans, s);
        }
    }
    cout << ans << '\n';
    return 0;
}