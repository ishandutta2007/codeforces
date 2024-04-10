#include <bits/stdc++.h>

#define INF INT_MAX
#define ll long long
#define endl '\n'
#define fc first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif   
    int ans = 0;
    int n, h, x;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans += (x > h ? 2 : 1);
    }
    cout << ans << endl;
}