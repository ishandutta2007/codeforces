#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 300000;

int n, m;
int fac[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1LL * fac[i - 1] * i % m;
    }
    int ans =  0;
    for (int i = 1; i <= n; i++) {
        int temp = fac[i];
        temp = 1LL * temp * fac[n - i + 1] % m; 
        temp = 1LL * temp * (n - i + 1) % m;
        ans = (ans + temp) % m;
    }
    cout << ans;
    return 0;
}