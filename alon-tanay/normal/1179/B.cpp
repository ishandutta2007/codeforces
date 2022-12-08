#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int x = 1, y = 1;
    int r1 = 1;
    int r2 = n;
    while(r1 < r2) {
        for(int i = 1; i <= m; i ++) {
            cout << r1 << " " << i << "\n";
            cout << r2 << " " << (m+1-i) << "\n";
        }
        r1 ++;
        r2 --;
    }
    if(r1 == r2) {
        int i = 1;
        for(; i <= m/2; i ++) {
            cout << r1 << " " << i << "\n";
            cout << r1 << " " << (m+1-i) << "\n";
        }
        if(i * 2 - 1 == m) {
            cout << r1 << " " << i << "\n";
        }
    }
    return 0;
    for(int ri = 0; ri < n; ri ++) {
        for(int i = 0; i < m; i ++) {
            cout << x << " " << y << "\n";
            y = m - y + 1;
            if(y <= m/2) {
                y ++;
            }
        }
        y = 1;
        x = n - x + 1;
        if(x <= n / 2) {
            x ++;
        }
    }
    return 0;
}