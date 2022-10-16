#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    long long ans = 0;
    for(int i = 0, j = 0; i < n; i++) {
        while(j < n && x[j] - x[i] <= d)
            j++;
        ans += ((long long)(j - i - 1) * (j - i - 2)) / 2;
    }
    cout << ans << '\n';
    return 0;
}