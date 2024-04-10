#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const ll INF = 2e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string prev(51, 'a');
        cout << prev << "\n";
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            string now = "";
            for (int j = 0; j < x; j++) now += prev[j];
            if (prev[x] == 'b') now += 'a';
            else now += 'b';
            for (int j = x + 1; j < 51; j++) now += 'a';
            cout << now << "\n";
            prev = now;
        }
    }
    return 0;
}