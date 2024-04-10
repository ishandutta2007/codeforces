#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int left = 0, right = INF;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (mid <= a && mid <= b && a - mid + b - mid >= mid) left = mid;
            else right = mid;
        }
        cout << left << "\n";
    }
    return 0;
}