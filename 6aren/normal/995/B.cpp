#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int a[205];

void insert(int x, int y) {
    int temp = a[y];
    for (int i = y; i >= x + 1; i--) {
        a[i] = a[i - 1];
    }
    a[x] = temp;
    return;
}

bool check[105];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (check[a[i]]) continue;
        int pos = 0;
        for (int j = i + 1; j <= 2 * n; j++) {
            if (a[j] == a[i]) pos = j;
        }
        ans += pos - i - 1;
        insert(i + 1, pos);
        check[a[i]] = 1;
    }
    cout << ans;
    return 0;
}