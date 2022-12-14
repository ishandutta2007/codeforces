#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    int m = 1;
    for (int i = 0; i < n - 1; i++){
        if (a[i] != a[i + 1]){
            if (m * n >= k){
                bool pekh = (k % m == 0);
                cout << a[i] << " " << a[k / m - pekh] << endl;
                return 0;
            }
            k -= m * n;
            m = 1;
        }
        else
            m ++;
    }
    bool cur;
    if (k % m == 0)
        cur = 1;
    cout << a[n - 1] << " " << a[k / m - cur];
}