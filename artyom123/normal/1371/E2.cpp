#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

mt19937 gen(time(0));

int n, p;
vector<int> a;

bool ans_exists(int x) {
    bool f = true;
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] <= x + i) {
            cnt++;
            j++;
        }
        if (cnt - i == 0) {
            f = false;
            break;
        }
    }
    return f;
}

bool check_div(int x) {
    bool f = true;
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] <= x + i) {
            cnt++;
            j++;
        }
        if ((cnt - i) % p == 0) {
            f = false;
            break;
        }
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    a.resize(n);
    for (auto &c : a) cin >> c;
    sort(all(a));
    int left = 0, right = 1e9;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (ans_exists(mid)) right = mid;
        else left = mid;
    }
    int ansl = right;
    left = ansl - 1, right = 1e9;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check_div(mid)) left = mid;
        else right = mid;
    }
    int ansr = left;
    cout << max(0, ansr - ansl + 1) << "\n";
    for (int i = ansl; i <= ansr; i++) cout << i << " ";
    return 0;
}