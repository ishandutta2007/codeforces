#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, k, g, cnt = 0;
        cin >> a >> b >> k;
        g = gcd(a, b);
        if (k == 1) {
            if (a == b)
                cout << "No\n";
            else if (a == g || b == g)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        for (int i = 2; i * i <= a; ++i)
            while (a % i == 0)
                ++cnt, a /= i;
        cnt += (a > 1);
        for (int i = 2; i * i <= b; ++i)
            while (b % i == 0)
                ++cnt, b /= i;
        cnt += (b > 1);
        if (k <= cnt)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}