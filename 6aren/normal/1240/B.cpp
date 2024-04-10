#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 300005;

int n, a[N], comp[N], mx[N], mn[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest;
    cin >> nTest;
    while (nTest--) {
        cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int cur = 1;
        int compSize = s.size();
        for (auto u : s) {
            comp[u] = cur++;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = comp[a[i]];
            mx[a[i]] = i;
        }
        for (int i = n; i >= 1; i--) {
            mn[a[i]] = i;
        }
        int maxilen = 0;
        cur = 1;
        for (int i = 2; i <= compSize; i++) {
            if (mn[i] > mx[i - 1]) {
                cur++;
            } else {
                maxilen = max(maxilen, cur);
                cur = 1;
            }
        }
        maxilen = max(maxilen, cur);
        cout << compSize - maxilen << '\n';
    }
    return 0;
}