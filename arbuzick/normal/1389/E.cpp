#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int gsd(int a, int b){
    while(b)
        a %= b, swap(a, b);
    return a;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m, d, w;
        cin >> m >> d >> w;
        int w1 = w/gsd(d-1, w), k = min(d, m)/w1;
        cout << min(d, m)*k-(1+k)*k/2*w1 << '\n';
    }
    return 0;
}