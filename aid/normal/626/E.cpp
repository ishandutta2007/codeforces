#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int a[MAXN];
long long ps[MAXN];

long long get(int l, int r) {
    return ps[r] - ps[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ps[0] = 0;
    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];
    long long med = a[0], s = a[0], k = 1;
    int pos = 0;
    for(int i = 0; i < n; i++) {
        int l = 0, r = min(i, n - i - 1) + 1;
        while(l < r - 1) {
            int m = (l + r) / 2;
            long long sum = get(i - m + 1, i) + a[i] + get(n - m + 1, n);
            if((long long)(a[i - m] + a[n - m]) * (2 * m - 1) > sum * 2)
                l = m;
            else
                r = m;
        }
        long long sum = get(i - l, i) + a[i] + get(n - l, n);
        if(s * (2 * l + 1) - med * k * (2 * l + 1) <
           sum * k - a[i] * k * (2 * l + 1)) {
            s = sum;
            k = 2 * l + 1;
            med = a[i];
            pos = i;
        }
    }
    cout << k << '\n';
    for(int i = pos - k / 2; i <= pos; i++)
        cout << a[i] << ' ';
    for(int i = n - k / 2; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}