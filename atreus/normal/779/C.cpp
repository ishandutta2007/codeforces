#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 500;
int a[maxn], b[maxn];
pair <int, int> c[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++){
        c[i].first = a[i] - b[i];
        c[i].second = i;
    }
    sort (c, c + n);
    long long ans = 0;
    for (int i = 0; i < k; i++){
        ans += a[c[i].second];
    }
    int andice = k - 1;
    for (int i = k; i < n; i++){
        if (c[i].first < 0){
            andice = i;
            ans += a[c[i].second];
        }
        else
            break;
    }
    for (int i = andice + 1; i < n; i++){
        ans += b[c[i].second];
    }
    cout << ans << endl;
}