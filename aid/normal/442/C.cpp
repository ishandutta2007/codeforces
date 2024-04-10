#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500 * 1000 + 5;
int a[MAXN], next[MAXN], prev[MAXN];
pair<int, int> p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = make_pair(a[i], i);
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    sort(p, p + n);
    long long ans = 0;
    int l = 0, r = n - 1;
    for(int i = 0; i < n - 2; i++) {
        int pos = p[i].second;
        if(pos == l) {
            ans += a[pos];
            l = next[l];
            continue;
        }
        if(pos == r) {
            ans += a[pos];
            r = prev[r];
            continue;
        }
        ans += min(a[prev[pos]], a[next[pos]]);
        next[prev[pos]] = next[pos];
        prev[next[pos]] = prev[pos];
    }
    cout << ans << '\n';
    return 0;
}