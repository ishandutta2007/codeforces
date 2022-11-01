#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 1e6;
const int MAXSZ = 112;
typedef pair <int, int> pr;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    int ans = 0;
    fr(i, m) {
        int t1, t2;
        cin >> t1 >> t2;
        ans += min(a[t1 - 1], a[t2 - 1]);
    }
    cout << ans;
}