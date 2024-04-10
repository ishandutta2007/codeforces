#include <bits/stdc++.h>
using namespace std;

int n, b, a[105], dp[105][105];
vector<int> cut;

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] % 2 == 0) cnt++;
        if (2 * cnt == i + 1) cut.push_back(abs(a[i+1]-a[i]));
    }
    sort(cut.begin(), cut.end());
    int tot = 0;
    cnt = 0;
    for (int i = 0; i < cut.size(); i++) {
        tot += cut[i];
        if (tot <= b) cnt++;
        else break;
    }
    cout << cnt << endl;
}