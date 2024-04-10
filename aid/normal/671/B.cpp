#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500 * 1000 + 5;
const int INF = 1000 * 1000 * 1000 + 5;
int c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    sort(c, c + n, greater<int>());
    int endVal = sum / n, endRich = sum % n;
    long long endTime = 0;
    for(int i = 0; i < n; i++)
        if(i < endRich) {
            if(c[i] > endVal + 1)
                endTime += c[i] - endVal - 1;
        }
        else {
            if(c[i] > endVal)
                endTime += c[i] - endVal;
        }
    if(k >= endTime) {
        cout << (endRich? 1 : 0) << '\n';
        return 0;
    }
    int l = endVal + (endRich? 1 : 0) - 1, r = INF;
    while(l < r - 1) {
        int m = (l + r) / 2;
        long long t = 0;
        for(int i = 0; i < n; i++)
            if(c[i] > m)
                t += c[i] - m;
        if(t > k)
            l = m;
        else
            r = m;
    }
    int ans = r;
    l = 0;
    r = endVal + 1;
    while(l < r - 1) {
        int m = (l + r) / 2;
        long long t = 0;
        for(int i = 0; i < n; i++)
            if(c[i] < m)
                t += m - c[i];
        if(t > k)
            r = m;
        else
            l = m;
    }
    ans -= l;
    cout << ans << '\n';
    return 0;
}